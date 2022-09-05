//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
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
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
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
const int maxn=400111;
struct SAM
{
	int go[maxn][5],pre[maxn],len[maxn],tot,last;
	ll dis[maxn][4];
	bool vis[maxn];
	void init()
	{
		memset(go,-1,sizeof(go));
		memset(pre,-1,sizeof(pre));
		memset(len,0,sizeof(len));
		for(int i=0;i<maxn;i++)for(int j=0;j<4;j++)dis[i][j]=INF;
		memset(vis,0,sizeof(vis));
		tot=1;last=0;
	}
	void insert(char c)
	{
		c-='A';
		int p=last,np=tot++;
		len[np]=len[last]+1;
		while(p!=-1&&go[p][c]==-1)
			go[p][c]=np,p=pre[p];
		if(p==-1)
			pre[np]=0;
		else
		{
			int q=go[p][c];
			if(len[p]+1==len[q])
				pre[np]=q;
			else
			{
				int nq=tot++;
				len[nq]=len[p]+1;
				for(int i=0;i<5;i++)
					go[nq][i]=go[q][i];
				pre[nq]=pre[q];
				pre[q]=pre[np]=nq;
				while(p!=-1&&go[p][c]==q)
					go[p][c]=nq,p=pre[p];
			}
		}
		last=np;
	}
	void dfs(int p)
	{
		vis[p]=1;
		for(int i=0;i<4;i++)
		{
			int u=go[p][i];
			if(u==-1)
				dis[p][i]=0;
			else
			{
				if(!vis[u])
					dfs(u);
				for(int j=0;j<4;j++)
					dis[p][j]=min(dis[p][j],dis[u][j]+1);
			}
		}
	}
}sam;
const ll llmax=1ll<<61;
struct matrix
{
	ll a[4][4];
	matrix(){for(int i=0;i<4;i++)for(int j=0;j<4;j++)a[i][j]=llmax;}
	void sete()
	{
		for(int i=0;i<4;i++)for(int j=0;j<4;j++)a[i][j]=llmax;
		for(int i=0;i<4;i++)a[i][i]=0;
	}
	matrix operator*(const matrix &tmp)
	{
		matrix ans;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					ans.a[i][j]=min(llmax,min(ans.a[i][j],a[i][k]+tmp.a[k][j]));
		return ans;
	}
	ll result()
	{
		ll ans=a[0][0];
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				ans=min(ans,a[i][j]);
		return ans;
	}
}pw[63],t;
char s[maxn];
ll n;
int len;
int main()
{
	sam.init();
	geti(n);
	n--;
	scanf("%s",s+1);
	len=strlen(s+1);
	sam.insert('E');
	for(int i=1;i<=len;i++)sam.insert(s[i]);
	sam.dfs(0);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			pw[0].a[i][j]=sam.dis[sam.go[0][i]][j]+1;
	for(int i=1;i<63;i++)pw[i]=pw[i-1]*pw[i-1];
	ll ans=0;
	t.sete();
	for(int i=62;i>=0;i--)
	{
		ll tans=(t*pw[i]).result();
		if(tans<=n)
		{
			ans+=1ll<<i;
			t=t*pw[i];
		}
	}
	putsi(ans+1);
	return 0;
}