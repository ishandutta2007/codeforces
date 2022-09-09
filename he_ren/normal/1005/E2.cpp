#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void init(int _n){ n = _n; memset(tree,0,sizeof(tree));}
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
}tree;

int n;
int a[MAXN];

inline ll get_res(int lim)
{
	static int sum[MAXN];
	static pii val[MAXN];
	val[0] = {0, 0};
	for(int i=1; i<=n; ++i)
	{
		sum[i] = sum[i-1] + (a[i] > lim);
		val[i] = {i - 2 * sum[i], i};
	}
	
	ll res = 0;
	sort(val, val+n+1);
	tree.init(n+1);
	for(int i=0; i<=n; ++i)
	{
		res += tree.query(val[i].second + 1);
		tree.update(val[i].second + 1, 1);
	}
	return res;
}

int main(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	printf("%lld",get_res(m) - get_res(m-1));
	return 0;
}