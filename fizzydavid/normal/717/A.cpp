//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1e9+7;
ll kissme(ll x,ll t)
{
	ll ans=1;
	while(t>0)
	{
		if(t&1)ans=ans*x%mod;
		x=x*x%mod;
		t>>=1;
	}
	return ans;
}
struct number
{
	int x,y;//x+ysqrt(5)
	number(int _x=0,int _y=0){x=_x;y=_y;}
	number operator+(number t){return number((x+t.x)%mod,(y+t.y)%mod);}
	number operator-(number t){return number((x-t.x+mod)%mod,(y-t.y+mod)%mod);}
	number operator*(number t){return number((1ll*x*t.x+1ll*y*t.y*5)%mod,(1ll*x*t.y+1ll*y*t.x)%mod);}
	number operator*(int t){return number((1ll*x*t)%mod,(1ll*y*t)%mod);}
	bool operator!=(number t){return x!=t.x||y!=t.y;}
	number inv()
	{
		ll t=(1ll*x*x%mod-5ll*y*y%mod+mod)%mod;
		t=kissme(t,mod-2);
		return number(x*t%mod,(-y*t%mod+mod)%mod);
	}
	void operator=(int t){x=t;y=0;}
	number operator^(ll t)
	{
		number ret(1,0),b=(*this);
		while(t>0)
		{
			if(t&1)ret=ret*b;
			b=b*b;
			t>>=1;
		}
		return ret;
	}
	void out(){cout<<x<<","<<y<<endl;}
};
number sigma(number x,ll l,ll r)
{
	if(x.x==1&&x.y==0)return (r-l+1)%mod;
	else return ((x^l)-(x^(r+1)))*(number(1,0)-x).inv();
}
ll k,l,r;
ll dp[211];
ll f[211],revf[211];
ll C(ll x,ll y)
{
	if(x<y)return 0;
	else return f[x]*revf[y]%mod*revf[x-y]%mod;
}
number A,B,pa[211],pb[211];
int sign(ll n){return n&1?mod-1:1;}
ll solve(ll l,ll r)
{
	number c=1,bs=number(0,kissme(5,mod-2));
	number sum;
	for(int i=1;i<=k;i++)
	{
		c=c*bs;
		number tsum;
		for(int j=0;j<=i;j++)
		{
			tsum=tsum+sigma(pa[j]*pb[i-j],l,r)*C(i,j)*sign(i-j);
		}
		tsum=tsum*c;
		sum=sum+tsum*dp[i];
	}
	return sum.x;
}
int main()
{
	f[0]=1;
	for(int i=1;i<=205;i++)f[i]=f[i-1]*i%mod;
	revf[205]=kissme(f[205],mod-2);
	for(int i=204;i>=0;i--)revf[i]=revf[i+1]*(i+1)%mod;
	number A=number(1,1)*kissme(2,mod-2),B=number(1,0)-A;
	pa[0]=1;pb[0]=1;
	for(int i=1;i<=205;i++)pa[i]=pa[i-1]*A,pb[i]=pb[i-1]*B;
	cin>>k>>l>>r;
	l+=2;r+=2;
	dp[1]=1;
	ll fac=1;
	for(int i=1;i<k;i++)
	{
		fac=fac*(i+1)%mod;
		for(int j=i;j>=0;j--)
		{
			dp[j+1]=(dp[j+1]+dp[j])%mod;
			dp[j]=dp[j]*(-i+mod)%mod;
		}
	}
	cout<<solve(l,r)%mod*kissme(fac,mod-2)%mod<<endl;
	return 0;
}