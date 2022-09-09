#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

int fa[MAXN];
inline void clear(int n){ for(int i=1; i<=n; ++i) fa[i]=i;}
int find(int u){ return fa[u]==u? u: fa[u]=find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	clear(n);
	for(int k=1; k<=m; ++k)
	{
		int d;
		scanf("%d",&d);
		int lst = -1;
		for(int i=1; i<=d; ++i)
		{
			int u;
			scanf("%d",&u);
			if(i>1) connect(u,lst);
			lst = u;
		}
	}
	
	static int size[MAXN];
	for(int i=1; i<=n; ++i)
		++size[find(i)];
	
	for(int i=1; i<=n; ++i) printf("%d ",size[find(i)]);
	return 0;
}