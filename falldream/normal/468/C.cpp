#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define N 1000000000
using namespace std;
long long tmp[6],n,occ[1005],Res[1005],P[25];
struct G
{
	int s[5],len;
	G(){len=0;memset(s,0,sizeof(s));}
	G(ll x){memset(s,0,sizeof(s));for(len=0;x;x/=N) s[len++]=x%N;}
	G operator * (const G&b)
	{
		G c;c.len=min(len+b.len,5);
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<len;++i)
			for(int j=0;j<b.len;++j)
				tmp[i+j]+=1LL*s[i]*b.s[j];
		for(int i=0;i<c.len;++i) c.s[i]=tmp[i]%N,tmp[i+1]+=tmp[i]/N;
		for(;c.len&&c.s[c.len-1]==0;)--c.len;
		return c;
	}
	friend bool operator < (const G&a,const G&b)
	{
		if(a.len!=b.len) return a.len<b.len;
		for(int i=a.len-1;i>=0;--i) 
			if(a.s[i]<b.s[i]) return true;
			else if(a.s[i]>b.s[i]) return false;
		return false;
	}
	G operator - (const G&b)
	{
		G c;c.len=len;
		for(int i=0;i<c.len;++i) 
			if((c.s[i]+=s[i]-b.s[i])<0) c.s[i]+=N,--c.s[i+1];	
		for(;c.len&&c.s[c.len-1]==0;) --c.len;
		return c;
	}
	G operator + (const G&b)
	{
		G c;c.len=max(b.len,len);
		for(int i=0;i<c.len;++i) 
		{
			c.s[i]+=s[i]+b.s[i];
			if(c.s[i]>=N) ++c.s[i+1],c.s[i]-=N;
		}
		for(;c.len<5&&c.s[c.len];) ++c.len;
		return c;
	}
	ll num()
	{
	//	cout<<"Calcnum";
	//	for(int i=len-1;i>=0;--i) printf("%d  ",s[i]);
	//	cout<<endl;
		ll x=0;
		for(int i=len-1;i>=0;--i)	
			x=x*N+s[i];
		return x;
	}
}pw[20],m,x;
int s[25],len;
G Calc(ll x)
{
//	cout<<"Calc"<<x<<endl;
	G res;len=0;ll pre=0;
	for(ll t=x;t;t/=10) s[++len]=t%10,P[len]=0;
	for(int i=1;i<=len;++i) for(int j=i;j;--j) P[i]=P[i]*10+s[j];
	for(int i=len;i;pre=pre*10+s[i],--i) for(int j=1;j<=9;++j)
	{
	//	cout<<i<<" "<<pre<<" *1e"<<i-1<<"*"<<j<<endl;
		res=res+G(pre)*pw[i-1]*G(j);
		if(j<s[i]) res=res+pw[i-1]*G(j);	
		else if(j==s[i]) res=res+G(j)*G(P[i-1]+1);
	}
	return res;
}

int main()
{
	scanf("%lld",&n);m=G(n);pw[0]=G(1);
	for(int i=1;i<=18;++i) pw[i]=pw[i-1]*G(10);
	for(int t=1;;++t)
	{
		x=x+m;
		long long l=1,r=4e18,mid,res;
		while(l<=r)
		{
			mid=l+r>>1;
			if(Calc(mid)<x) l=mid+1;
			else res=mid,r=mid-1; 
		}
	//	cout<<x.num()<<endl;
	//	cout<<Calc(res).num();
		ll f=(Calc(res)-x).num();
	//	cout<<t<<" "<<res<<" "<<f<<endl;
		if(occ[f]) return 0*printf("%lld %lld\n",Res[occ[f]]+1,res);
		else occ[f]=t,Res[t]=res;
	}
	return 0;
}