#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

struct BIT
{
	int tree[MAXN*2], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		while(x<=n)
			add_mod(tree[x], k),
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			add_mod(res, tree[x]),
			x ^= lowbit(x);
		return res;
	}
	inline int query(int l,int r)
	{
		int res = query(r) - query(l-1);
		return res < 0? res + mod: res;
	}
}tree;

int a[MAXN], b[MAXN];
pii p[MAXN];
bool is[MAXN], fin[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		p[i] = {a[i], i};
	}
	int m;
	scanf("%d",&m);
	set<int> t;
	for(int i=1; i<=m; ++i)
	{
		int x;
		scanf("%d",&x);
		is[x] = 1; t.insert(b[x]);
	}
	
	sort(p+1,p+n+1);
	for(int i=1; i<=n; ++i)
	{
		int x = p[i].second;
		auto it = t.lower_bound(b[x]);
		if(it != t.end()) fin[x] = 1;
		if(is[x]) t.erase(it);
	}
	
	tree.n = 2 * n;
	int ans = 0;
	static int dp[MAXN];
	for(int i=1; i<=n; ++i)
	{
		int x = p[i].second;
		dp[x] = tree.query(b[x], 2 * n);
		if(fin[x]) add_mod(dp[x], 1);
		add_mod(ans, dp[x]);
		tree.update(b[x], dp[x]);
	}
	
	printf("%d",ans);
	return 0;
}