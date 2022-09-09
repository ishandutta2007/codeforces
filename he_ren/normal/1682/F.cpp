#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}
inline int mod_add(int a,int b){ return a+b>=mod? a+b-mod: a+b;}

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		k %= mod; if(k<0) k += mod;
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
		return mod_add(query(r), mod - query(l-1));
	}
};

int a[MAXN], b[MAXN], ans[MAXQ];
vector<pii> qs[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	static ll sumb[MAXN];
	for(int i=1; i<=n; ++i)
		sumb[i] = sumb[i-1] + b[i];
	
	static ll dsc[MAXN];
	int dcnt = 0;
	for(int i=0; i<=n; ++i) dsc[++dcnt] = sumb[i];
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	
	static int dval[MAXN];
	for(int i=0; i<=n; ++i)
		dval[i] = lower_bound(dsc+1,dsc+dcnt+1,sumb[i]) - dsc;
	
	for(int i=1; i<=Q; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		qs[l-1].emplace_back(dval[l-1], -i);
		qs[r].emplace_back(dval[l-1], i);
	}
	
	static BIT tree[2];
	tree[0].n = tree[1].n = dcnt;
	auto upd = [&] (int k,int coef)
	{
		tree[0].update(k, dsc[k] %mod * coef %mod);
		tree[1].update(k, coef);
	};
	auto query = [&] (int k) -> int
	{
		ll c = dsc[k] %mod;
		ll res = 0;
		res = (res + tree[0].query(k, dcnt) - tree[1].query(k, dcnt) * c) %mod;
		res = (res - tree[0].query(1, k-1) + tree[1].query(1, k-1) * c) %mod;
		if(res<0) res += mod;
		return res;
	};
	for(int i=1; i<=n; ++i)
	{
		upd(dval[i-1], a[i]); upd(dval[i], -a[i]);
		for(auto t: qs[i])
		{
			int cur = query(t.first), id = abs(t.second);
			if(t.second > 0)
				add_mod(ans[id], cur);
			else
				add_mod(ans[id], mod - cur);
		}
	}
	
	for(int i=1; i<=Q; ++i)
		printf("%d\n",ans[i]);
	return 0;
}