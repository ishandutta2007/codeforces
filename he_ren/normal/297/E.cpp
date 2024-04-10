#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

inline ll C2(ll n){ return n * (n-1) / 2;}
inline ll C3(ll n){ return n * (n-1) * (n-2) / 6;}

struct BIT
{
	int tree[MAXN * 2], n;
	#define lowbit(x) ((x)&-(x))
	inline void clear(int _n){ n = _n; memset(tree,0,sizeof(tree));}
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline void update(int l,int r,int k){ update(l, k); update(r+1, -k);}
	inline int query(int x)
	{
		int res=0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline int query(int l,int r){ return query(r) - query(l-1);}
}tree, tree2;

int n;
int a[MAXN], b[MAXN];

int f[MAXN], g[MAXN];
void update_fg(void)
{
	static int to[MAXN * 2];
	memset(to, -1, sizeof(to));
	for(int i=1; i<=n; ++i) to[b[i]] = i;
	
	tree.clear(2 * n);
	tree2.clear(2 * n);
	for(int i=1; i<=2*n; ++i) if(to[i] != -1)
	{
		int id = to[i];
		f[id] += tree.query(a[id]);
		g[id] += tree2.query(a[id], b[id]);
		tree.update(a[id], b[id], 1);
		tree2.update(a[id], 1);
	}
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	
	for(int i=1; i<=n; ++i)
		if(a[i] > b[i]) swap(a[i], b[i]);
	update_fg();
	for(int i=1; i<=n; ++i)
		swap(a[i] = 2 * n - a[i] + 1, b[i] = 2 * n - b[i] + 1);
	update_fg();
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
		ans += C2(f[i]) + C2(n - 1 - f[i]);
	ans = (ans - C3(n)) / 2;
	
	for(int i=1; i<=n; ++i)
	{
		g[i] /= 2;
		ans -= (ll)g[i] * (n - 1 - g[i] - f[i]);
	}
	printf("%lld",ans);
	return 0;
}