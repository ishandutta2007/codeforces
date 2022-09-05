//by yjz
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
ll fac[600111],ifac[600111],pw2[600111],cntg[300111];
ll kissme(ll x,ll k)
{
	ll ans=1;
	while(k>0)
	{
		if(k&1)ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
int n,l1,l2,a1,b1,c1,a2,b2,c2,cc;
char s1[300111],s2[300111];
bool same;
ll C(int x,int y){return x<y?0:fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
void precalc()
{
	pw2[0]=1;
	for(int i=1;i<=600000;i++)pw2[i]=pw2[i-1]*2%mod;
	fac[0]=1;
	for(int i=1;i<=600000;i++)fac[i]=fac[i-1]*i%mod;
	ifac[600000]=kissme(fac[600000],mod-2);
	for(int i=599999;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	for(int i=n;i>=1;i--)
	{
		cntg[i]=1ll*(n/i)*(n/i)%mod;
		for(int j=i+i;j<=n;j+=i)cntg[i]-=cntg[j];
		cntg[i]=(cntg[i]%mod+mod)%mod;
	}
}
int main()
{
	scanf("%s",s1);l1=strlen(s1);
	scanf("%s",s2);l2=strlen(s2);
	cin>>n;
	precalc();
	if(l1==l2)
	{
		same=1;
		for(int i=0;i<l1;i++)same&=s1[i]=='?'||s2[i]=='?'||s1[i]==s2[i];
	}
	for(int i=0;i<l1;i++)
	{
		a1+=s1[i]=='A';
		b1+=s1[i]=='B';
		c1+=s1[i]=='?';
		cc+=s1[i]=='?'&&s2[i]=='?';
	}
	for(int i=0;i<l2;i++)
	{
		a2+=s2[i]=='A';
		b2+=s2[i]=='B';
		c2+=s2[i]=='?';
	}
	ll ans=0;
	for(int dlt=-l2;dlt<=l1;dlt++)
	{
		int dltb=l1-l2-dlt;
		int tmp=dlt-a1+a2+c2;
		if(tmp<0||tmp>c1+c2)continue;
		ll cnt=C(c1+c2,tmp);
		if(cnt==0)continue;
		if(dlt==0&&dltb==0)
		{
			if(same)
			{
				ans+=1ll*pw2[cc]*(pw2[n+1]+mod-2)%mod*(pw2[n+1]+mod-2)%mod;
				cnt=(cnt-pw2[cc]+mod)%mod;
			}
			for(int i=1;i<=n;i++)
			{
				ans+=1ll*cntg[i]*pw2[i]%mod*cnt%mod;
			}
		}
		else if(1ll*dlt*dltb<0)
		{
			int x=abs(dltb),y=abs(dlt),g=__gcd(x,y);
			x/=g;y/=g;
			ans+=1ll*cnt*(pw2[n/max(x,y)+1]-2+mod)%mod;
		}
	}
	cout<<ans%mod<<endl;
	return 0;
}