//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
struct TRIE
{
	int go[600111][26],sum[600111],tot;
	TRIE()
	{
		memset(sum,0,sizeof(sum));
		memset(go,0,sizeof(go));
		tot=0;
	}
	void update(int p)
	{
		sum[p]=1;
		for(int i=0;i<26;i++)sum[p]+=sum[go[p][i]];
	}
	void combine(int p,int q)//q to p
	{
if(p==q)return;
		for(int i=0;i<26;i++)
		{
			if(go[q][i])
			{
				if(!go[p][i])go[p][i]=go[q][i];
				combine(go[p][i],go[q][i]);
			}
		}
		update(p);
	}
}A;
int n,c[300111],sz[300111],ans,anscnt,rt[300111];
char s[300111];
vector<int>con[300111];
void dfs(int x,int p=-1)
{
	sz[x]=1;
	int mx=0,mxi=0;
	for(auto u:con[x])
	{
		if(u==p)continue;
		dfs(u,x);
		sz[x]+=sz[u];
		if(sz[u]>mx)
		{
			mx=sz[u];
			mxi=u;
		}
	}
	if(mx==0)
	{
		rt[x]=++A.tot;
		A.go[rt[x]][s[x]-'a']=++A.tot;
		A.sum[A.tot]=1;
		A.sum[A.tot-1]=2;
	}
	else
	{
		for(auto u:con[x])
		{
			if(u==p||u==mxi)continue;
			A.combine(rt[mxi],rt[u]);
		}
		rt[x]=++A.tot;
		A.go[rt[x]][s[x]-'a']=rt[mxi];
		A.sum[A.tot]=A.sum[rt[mxi]]+1;
	}
	int cur=A.sum[rt[x]]+c[x]-1;
	if(cur>ans)ans=cur,anscnt=1;
	else if(cur==ans)anscnt++;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(c[i]);
	scanf("%s",s+1);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs(1);
	cout<<ans<<" "<<anscnt<<endl;
	return 0;
}