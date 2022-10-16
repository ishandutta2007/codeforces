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
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	ll jiec[xx],ni[xx];
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
	const int xx=5e5+5,mod=998244353;
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
int n,m,k,q,ans,a[xx],t[xx];
char s[xx];
int vs[xx];
int main(){
	int T=read();
	while(T--)
	{
		n=read();k=read();
		if(n==4&k==0)
		{
			puts("0 3");
			puts("1 2");
			continue;
		}
		if(n==4&k==1)
		{
			puts("0 2");
			puts("1 3");
			continue;
		}
		if(n==4&k==2)
		{
			puts("0 1");
			puts("3 2");
			continue;
		}
		if(n==4&&k==3)
		{
			puts("-1");
			continue;
		}
		int O=n-1;
		if(k==0)
		{
			for(int i=0;i<n;i++)
			{
				if(i<O-i)
				cout<<i<<" "<<O-i<<"\n";
			}
			continue;
		}
		int w=log2(n);
		for(int i=0;i<n;i++)vs[i]=0;
		vector<int>v;
		for(int i=0;i<w;i++)
			if(k>>i&1)v.push_back((1<<i));
		vector<pair<int,int> >ans;
		for(int i=0;i<v.size()-1;i++)
		{
			vs[v[i]]=1,vs[O-v[i+1]]=1;
			ans.push_back(make_pair(v[i],O-v[i+1]));
		}
		vs[v[v.size()-1]]=1;
		vs[O]=1;
		ans.push_back(make_pair(v[v.size()-1],O));
		for(int i=1;i<n;i++)
		{
			if(vs[i])continue;
			if(!vs[i]&&vs[O-i])
			{
				vs[i]=vs[0]=1;
				ans.push_back(make_pair(i,0));
			}
			else 
			{
				vs[i]=vs[O-i]=1;
				ans.push_back(make_pair(i,O-i));
			}
		}
		for(auto it:ans)cout<<it.first<<" "<<it.second<<"\n";
		
		
		
		
		
		
//		ans=0;
//		for(int i=1;i<=n;i++)a[i]=read();
//		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}