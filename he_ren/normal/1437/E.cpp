#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int inf = 0x3f3f3f3f;

struct BIT
{
	int tree[MAXN], l, r, n;// range[l, r]
	#define lowbit(x) ((x)&-(x))
	inline void clear(int l_,int r_)
	{
		l = l_; r = r_;
		n = r-l+1;
		for(int i=1; i<=n; ++i)
			tree[i] = -inf;
	}
	inline void update(int x,int k)
	{
		x = x-l+1;
		while(x<=n)
			tree[x] = max(tree[x], k),
			x += lowbit(x);
	}
	inline int query(int x)
	{
		x = x-l+1;
		int res = -inf;
		while(x)
			res = max(res, tree[x]),
			x ^= lowbit(x);
		return res;
	}
};

int a[MAXN], b[MAXN];

int calc(int l,int r)
{
	vector<pii> vec;
	for(int i=l; i<=r; ++i)
		vec.push_back(make_pair(a[i] - i, i));
	sort(vec.begin(), vec.end());
	
	static int f[MAXN];
	
	static BIT tree;
	tree.clear(l,r);
	
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int pos = vec[i].second;
		if(pos == l) f[pos] = 1;
		else
		{
			f[pos] = tree.query(pos);
			if(f[pos] == -inf) continue;
			++f[pos];
		}
		
		tree.update(pos, f[pos]);
	}
	
	if(f[r] == -inf) printf("-1"), exit(0);
	
	return r-l+1 - f[r];
}

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=d; ++i) scanf("%d",&b[i]);
	
	a[0] = -inf; a[n+1] = inf;
	b[0] = 0; b[d+1] = n+1;
	
	int ans = 0;
	for(int i=1; i<=d+1; ++i)
		ans += calc(b[i-1], b[i]);
	printf("%d",ans);
	return 0;
}