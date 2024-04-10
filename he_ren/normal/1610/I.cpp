#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

vector<int> g[MAXN];

int anc[MAXN], f[MAXN];
void dfs_f(int u,int fa)
{
	anc[u] = fa;
	for(int v: g[u]) if(v != fa)
	{
		dfs_f(v,u);
		f[u] ^= f[v] + 1;
	}
}

bool del[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	dfs_f(1,0);
	
	int res = f[1], cnt = 0;
	auto print = [&] (void)
	{
		bool ans = (res ^ (cnt % 2 == 1)) != 0;
//		if(cnt & 1) ans ^= 1;
		putchar(ans? '1': '2');
	};
	
	del[1] = 1; print();
	for(int i=2; i<=n; ++i)
	{
		if(del[i])
		{
			print();
			continue;
		}
		
		vector<int> node;
		for(int t=i; !del[t]; t = anc[t]) node.push_back(t);
		
		for(int u: node) del[u] = 1, ++cnt;
		
		res ^= f[node.back()] + 1;
		for(int u: node)
			for(int v: g[u]) if(v != anc[u] && !del[v])
				res ^= f[v] + 1;
		print();
	}
	return 0;
}