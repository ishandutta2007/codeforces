#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;                                                                              
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e6+5,mod=998244353,base=117;
int n,k;
char s[xx];
#define next nxt
int next[xx];
ll sum[xx],pw[xx],ni[xx];
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
ll get(int l,int r){return (sum[r]-sum[l-1]+mod)*ni[l]%mod;}
int mx[xx];
int main(){
	n=read(),k=read();
	scanf("%s",s+1);
	int p=0;
	for(int i=2;i<=n;i++)
	{
		while(p&&s[p+1]!=s[i])p=next[p];
		if(s[p+1]==s[i])p++;
		next[i]=p;
	}
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*base%mod;
	ni[0]=1;
	ni[1]=ksm(base,mod-2);
	for(int i=2;i<=n;i++)ni[i]=ni[i-1]*ni[1]%mod;
	for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+s[i]*pw[i]%mod)%mod;
	for(int i=1;i<=n;i++)
	{
		int xh=i-next[i];
		if(i%xh)continue;
		if(i%k)continue;
		if((i/k)%xh)continue;
		int len=i/k;
		int l=i+1,r=min(n,i+len),ans=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(get(i+1,mid)==get(1,mid-(i+1)+1))ans=mid,l=mid+1;
			else r=mid-1;
		}
//		cout<<get(i+1,i+1)<<" "<<get(1,1)<<"\n";
		mx[i]=ans-(i)+1;
	}
	int now=0;
	for(int i=1;i<=n;i++)
	{
		now=max(mx[i],now);
		if(now)
		{
			now--;
			cout<<1;
		}
		else cout<<0;
	}
	puts("");
	return 0;
}