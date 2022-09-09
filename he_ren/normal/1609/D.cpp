#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int fa[MAXN], siz[MAXN], cnt;
inline void init(int _n)
{
	cnt = _n;
	for(int i=1; i<=_n; ++i) fa[i] = i, siz[i] = 1;
}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v)
{
	u = find(u); v = find(v);
	if(u == v) return;
	fa[u] = v; siz[v] += siz[u]; --cnt;
}

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	init(n);
	for(int i=1; i<=d; ++i)
	{
		{
			int x,y;
			scanf("%d%d",&x,&y);
			connect(x,y);
		}
		
		int tot = n - cnt;
		assert(tot <= i);
		
		vector<int> a;
		for(int j=1; j<=n; ++j)
			if(fa[j] == j) a.push_back(siz[j]);
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		a.resize(i - tot + 1);
		
		int sum = accumulate(a.begin(), a.end(), 0);
		printf("%d\n",sum - 1);
	}
	return 0;
}