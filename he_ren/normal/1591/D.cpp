#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void clear(int _n)
	{
		n = _n;
		memset(tree, 0, (n+1)<<2);
	}
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

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	tree.clear(n);
	int ans = 0;
	for(int i=1; i<=n; ++i)
	{
		int x = a[i];
		if(tree.query(x) != tree.query(x-1))
		{
			printf("YES\n");
			return;
		}
		ans ^= (i-1 - tree.query(x)) & 1;
		tree.update(x,1);
	}
	
	if(ans) printf("NO\n");
	else printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}