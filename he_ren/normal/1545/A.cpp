#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void clear(int _n){ n = _n; memset(tree,0,(n+1)<<2);}
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
}tree;

int a[MAXN], b[MAXN];

inline bool chk_b(int l,int r)
{
	int cnt[2] = {0,0};
	for(int i=l; i<=r; ++i)
		if(b[i]) ++cnt[i&1];
	return cnt[0] == cnt[1];
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static pii p[MAXN];
	for(int i=1; i<=n; ++i) p[i] = make_pair(a[i], i);
	
	sort(p+1,p+n+1);
	tree.clear(n);
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && p[i].first == p[j].first) ++j;
		
		for(int k=i; k<j; ++k)
		{
			int pos = p[k].second;
			int num = i - 1 - tree.query(pos);
			b[k] = num & 1;
		}
		for(int k=i; k<j; ++k) tree.update(p[k].second, 1);
		for(int k=i; k<j; ++k)
		{
			int pos = p[k].second;
			int num = pos - tree.query(pos);
			b[k] ^= num & 1;
		}
		
		if(!chk_b(i, j-1)){ printf("NO\n"); return;}
	}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}