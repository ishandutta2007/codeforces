#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int n;
int fa[MAXN];
inline void init(int _n){ for(int i=1; i<=_n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

int main(void)
{
	int m1, m2;
	scanf("%d%d%d",&n,&m1,&m2);
	init(n*2);
	for(int i=1; i<=m1; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		connect(u,v);
	}
	for(int i=1; i<=m2; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		connect(u+n,v+n);
	}
	
	vector<pii> ans;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j) if(find(i) != find(j) && find(i+n) != find(j+n))
		{
			ans.emplace_back(i,j);
			connect(i,j);
			connect(i+n,j+n);
		}
	
	printf("%d\n",(int)ans.size());
	for(pii x: ans) printf("%d %d\n",x.first,x.second);
	return 0;
}