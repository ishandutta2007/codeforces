#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXA = 2e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int p[MAXA],pcnt=0;
bool isnp[MAXA];
int mnDiv[MAXA];
void primeInit(void)
{
	const int maxa = 2e5;
	isnp[0]=isnp[1]=1;
	for(int i=2; i<=maxa; ++i)
	{
		if(!isnp[i])
			mnDiv[i]=p[++pcnt]=i;
		for(int j=1; j<=pcnt; ++j)
		{
			if((ll)i*p[j]>maxa) break;
			isnp[i*p[j]]=1;
			mnDiv[i*p[j]]=p[j];
			if(!(i%p[j])) break;
		}
	}
}

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

struct Vector
{
	int a[30],cnt;
	Vector(){ cnt=0;}
	inline int& operator [] (int x){ return a[x];}
	inline int size(void){ return cnt;}
	inline void push_back(const int x){ a[++cnt]=x;}
	inline void clean(void)
	{
		sort(a+1,a+cnt+1);
		cnt=unique(a+1,a+cnt+1)-a-1;
	}
};

int a[MAXN];
Vector q[MAXN];
int mx1[MAXN][8],mx2[MAXN][8];

int ans=0;

void dfs(int u,int fa)
{	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
		
		for(int j=1; j<=q[u].size(); ++j)
			for(int k=1; k<=q[v].size(); ++k)
				if(q[u][j]==q[v][k])
				{
					if(mx1[u][j]<mx1[v][k])
						mx2[u][j]=mx1[u][j],
						mx1[u][j]=mx1[v][k];
					else if(mx2[u][j]<mx1[v][k])
						mx2[u][j]=mx1[v][k];
					break;
				}
	}
	
	for(int i=1; i<=q[u].size(); ++i)
		++mx1[u][i],
		chk_max(ans,mx1[u][i]+mx2[u][i]);
}

int main(void)
{
	primeInit();
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	for(int i=1; i<=n; ++i)
	{
		int tmp=a[i];
		while(tmp>1)
			q[i].push_back(mnDiv[tmp]),
			tmp /= mnDiv[tmp];
		q[i].clean();
	}
	
	dfs(1,0);
	printf("%d",ans);
	return 0;
}