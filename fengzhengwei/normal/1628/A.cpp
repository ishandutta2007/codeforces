#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=5e5+5,mod=998244353;
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
namespace zhs
{
	ll jiec[xx],ni[xx];
	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
	void pre()
	{
		jiec[0]=1;
		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
		ni[xx-1]=ksm(jiec[xx-1],mod-2);
		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	}
}
namespace pr
{
	int prim[xx],vis[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!vis[i])prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				vis[i*prim[j]]=1;
				if(i%prim[j]==0)break;
			}
		}
	}
}
int n,m,k,q,x,y,a[xx];
char s[xx];
vector<int>v[xx];
int tt[xx];
int main(){
//	freopen("a.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=0;i<=n+1;i++)v[i].clear();
		for(int i=0;i<=n+1;i++)tt[i]=0;
		for(int i=1;i<=n;i++)a[i]=read(),v[a[i]].push_back(i);
		int now=1;
		vector<int>ans;
		while(now!=n+1)
		{
			int j=0,mx=now;
			while(v[j].size()>tt[j])
			{
				mx=max(mx,v[j][tt[j]]);
				j++;
			}
			ans.push_back(j);
			for(int i=0;i<j;i++)
				while(tt[i]!=v[i].size()&&v[i][tt[i]]<=mx)tt[i]++;
			now=mx+1;
		}
		cout<<ans.size()<<"\n";
		for(auto it:ans)cout<<it<<" ";
		puts("");
	}
	pc('1',1);
	return 0;
}