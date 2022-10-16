#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
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
	int prim[xx],mn[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!mn[i])mn[i]=i,prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				mn[i*prim[j]]=prim[j];
				if(i%prim[j]==0)break;
			}
		}
	}
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
// 
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
int n,m,k,q,a[xx];
//char s[xx];
int fa[xx];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
set<int>s[xx];
void merge(int x,int y)
{
	if(find(x)==find(y))return;
	x=find(x),y=find(y);
	if(s[x].size()<s[y].size())
	{
		//y 
		fa[x]=y;
		for(auto it:s[x])
		{
			s[it].erase(x);
			s[it].insert(y);
			s[y].insert(it);
		}
		s[x].clear();
	}
	else 
	{
		fa[y]=x;
		for(auto it:s[y])
		{
			s[it].erase(y);
			s[it].insert(x);
			s[x].insert(it);
		}
		s[y].clear();
	}
}
int fa1[xx];// 
int find1(int x){return fa1[x]==x?x:fa1[x]=find1(fa1[x]);}
int main(){
	//log^2 
	//set 
	n=read(),m=read();
	for(int i=1;i<=n;i++)fa[i]=i,fa1[i]=i;
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==0)
		{
			int l=read(),r=read(),op=read();
			if(op==0)
			{
				l--;//sl-1~sr 
				int now=l;
				now=find1(now);
				while(now<r)
				{
					merge(find(now),find(now+1));
					fa1[now]=now+1;
					now=find1(now);
				}
			}
			else 
			{
				l--;
				s[find(l)].insert(find(r));
				s[find(r)].insert(find(l));
			}
		}
		else 
		{
			int x=read();
			x--;
			if(find(x)==find(x+1))
			{
				puts("NO");
				continue;
			}
			if(s[find(x)].find(find(x+1))!=s[find(x)].end())
			{
				puts("YES");
				continue;
			}
			puts("N/A");
		}
//		for(auto it:s[1])
//		{
//			cout<<it<<"!!\n"; 
//		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<find(i)<<" ";
//		}
//		puts("");
	}
	
	
//	int T=read();
//	while(T--)
//	{
//	}
	pc('1',1);
	return 0;
}