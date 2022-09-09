#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] = max(tree[x], k),
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			res = max(res, tree[x]),
			x ^= lowbit(x);
		return res;
	}
}tree;

pair<ll,ll> p[MAXN];

int main(void)
{
	int n,a,b,c,d;
	scanf("%d\n%d/%d %d/%d",&n,&a,&b,&c,&d);
	for(int i=1; i<=n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[i] = {(ll)x * c - (ll)y * d, (ll)x * a - (ll)y * b};
	}
	p[++n] = {0,0};
	
	sort(p+1,p+n+1); reverse(p+1,p+n+1);
	int lim = find(p+1,p+n+1,make_pair(0ll, 0ll)) - p;
	
	static ll dsc[MAXN];
	int dcnt = 0;
	for(int i=1; i<=n; ++i) dsc[++dcnt] = p[i].second;
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	
	tree.n = dcnt;
	for(int i=1; i<=lim; ++i)
	{
		int x = lower_bound(dsc+1,dsc+dcnt+1,p[i].second) - dsc;
		int res = tree.query(x - 1);
		if(i == lim) printf("%d",res);
		else tree.update(x, res + 1);
	}
	return 0;
}