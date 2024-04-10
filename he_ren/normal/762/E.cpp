#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXF = 1e4 + 5;

struct BIT
{
	int tree[MAXN],n;
	#define lowbit(x) ((x)&-(x))
	inline void clear(void){ memset(tree,0,(n+1)<<2);}
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
	inline int query(int l,int r){ return query(r) - query(l-1);}
};

struct Point_Counter
{
	int dsc[MAXN], dcnt;
	BIT tree;
	Point_Counter(void): dcnt(0) {}
	inline void clear(void){ dcnt = 0;}
	inline void add_point(int x){ dsc[++dcnt] = x;}
	inline void build(void)
	{
		sort(dsc+1,dsc+dcnt+1);
		dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
		tree.n = dcnt;
		tree.clear();
	}
	inline void update(int x,int k)
	{
		tree.update(lower_bound(dsc+1,dsc+dcnt+1,x) - dsc, k);
	}
	inline int query(int l,int r)
	{
		l = lower_bound(dsc+1,dsc+dcnt+1,l) - dsc;
		r = upper_bound(dsc+1,dsc+dcnt+1,r) - dsc - 1;
		return l <= r? tree.query(l,r): 0;
	}
}cntC, cntL;

inline ll get_res(vector<pii> &vec)
{
	cntC.clear(); cntL.clear();
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int x = vec[i].second;
		if(x > 0) cntC.add_point(x);
		else cntL.add_point(-x);
	}
	cntC.build(); cntL.build();
	
	ll res = 0;
	sort(vec.begin(), vec.end());
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int r = -vec[i].first, x = vec[i].second;
		if(x > 0)
		{
			res += cntL.query(x - r, x + r) + cntC.query(x - r, x + r);
			cntC.update(x, 1);
		}
		else
		{
			x = -x;
			res += cntC.query(x - r, x + r);
			cntL.update(x, 1);
		}
	}
	return res;
}

vector<pii> nodes[MAXF];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
	{
		int x,r,f;
		scanf("%d%d%d",&x,&r,&f);
		nodes[f].push_back(make_pair(-r,x));
	}
	
	ll ans = 0;
	for(int i=1; i<MAXF; ++i) if(nodes[i].size())
	{
		vector<pii> vec = nodes[i];
		for(int j=max(1, i-d); j<i; ++j)
			vec.insert(vec.end(), nodes[j].begin(), nodes[j].end());
		
		for(int j=nodes[i].size(); j<(int)vec.size(); ++j)
			vec[j].second = -vec[j].second;
		
		ans += get_res(vec);
	}
	
	printf("%lld",ans);
	return 0;
}