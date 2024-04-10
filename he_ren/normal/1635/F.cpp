#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXQ = 3e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct BIT_rev
{
	ll tree[MAXN];
	int n;
	#define lowbit(x) ((x)&-(x))
	inline void init(int _n)
	{
		n = _n;
		memset(tree, 0x3f, (n+1)<<3);
	}
	inline void update(int x,ll k)
	{
		x = n-x+1;
		while(x<=n)
			tree[x] = min(tree[x], k),
			x += lowbit(x);
	}
	inline ll query(int x)
	{
		x = n-x+1;
		ll res = linf;
		while(x)
			res = min(res, tree[x]),
			x ^= lowbit(x);
		return res;
	}
}tree;

int a[MAXN], b[MAXN];
pii qs[MAXQ];
ll res[MAXQ];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	for(int i=1; i<=Q; ++i) scanf("%d%d",&qs[i].first,&qs[i].second);
	
	memset(res, 0x3f, sizeof(res));
	for(int T=0; T<=1; ++T)
	{
		static vector<int> vec[MAXN];
		fill(vec+1, vec+n+1, vector<int>());
		for(int i=1; i<=Q; ++i)
			vec[qs[i].second].push_back(i);
		
		auto calc = [&] (int i,int j)
		{
			return (ll)abs(a[i] - a[j]) * (b[i] + b[j]);
		};
		
		tree.init(n);
		stack<int> sta;
		for(int i=1; i<=n; ++i)
		{
			while(sta.size() && b[sta.top()] > b[i]) sta.pop();
			if(sta.size())
				tree.update(sta.top(), calc(i, sta.top()));
			sta.push(i);
			
			for(int j: vec[i])
				res[j] = min(res[j], tree.query(qs[j].first));
		}
		
		reverse(a+1,a+n+1);
		reverse(b+1,b+n+1);
		for(int i=1; i<=n; ++i) a[i] = -a[i];
		for(int i=1; i<=Q; ++i)
			qs[i] = {n-qs[i].second+1, n-qs[i].first+1};
	}
	
	for(int i=1; i<=Q; ++i)
		printf("%lld\n",res[i]);
	return 0;
}