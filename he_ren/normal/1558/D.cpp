#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXP = MAXN * 3;
const int mod = 998244353;

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

const int MAXF = MAXN * 2;
ll fac[MAXF], inv[MAXF];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

inline int rnd(void){ return (rand() << 15) | rand();}

namespace Treap
{
	struct Node
	{
		Node *ls, *rs;
		int fix, siz, val, sum, vl, vr;
		Node(void){}
		Node(int _vl,int _vr,Node *emp): ls(emp), rs(emp), fix(rnd()), siz(1), val(_vl - _vr + 1), sum(val), vl(_vl), vr(_vr) {}
	}p[MAXP], *rt, *emp;
	int pcnt = 0;
	inline void init(void)
	{
		pcnt = 0;
		rt = emp = &p[0]; p[0] = Node(-1, 0, emp);
		p[0].siz = 0; p[0].val = p[0].sum = 0;
	}
	inline Node* new_Node(int vl,int vr)
	{
		return &(p[++pcnt] = Node(vl, vr, emp));
	}
	
	inline void push_up(Node *u)
	{
		u -> siz = u -> ls -> siz + u -> rs -> siz + 1;
		u -> sum = u -> ls -> sum + u -> rs -> sum + u -> val;
	}
	
	void split_sum(Node *u,Node *&l,Node *&r,int k)// sum < k
	{
		if(u == emp){ l = r = emp; return;}
		if(u -> ls -> sum + u -> val < k)
			l = u, split_sum(u -> rs, l -> rs, r, k - u -> ls -> sum - u -> val);
		else
			r = u, split_sum(u -> ls, l, r -> ls, k);
		if(l != emp) push_up(l);
		if(r != emp) push_up(r);
	}
	void split_siz(Node *u,Node *&l,Node *&r,int k)// siz == k
	{
		if(u == emp){ l = r = emp; return;}
		if(u -> ls -> siz + 1 <= k)
			l = u, split_siz(u -> rs, l -> rs, r, k - u -> ls -> siz - 1);
		else
			r = u, split_siz(u -> ls, l, r -> ls, k);
		if(l != emp) push_up(l);
		if(r != emp) push_up(r);
	}
	void merge(Node *&u,Node *l,Node *r)
	{
		if(l == emp){ u = r; return;}
		if(r == emp){ u = l; return;}
		if(l -> fix < r -> fix)
			u = l, merge(u -> rs, l -> rs, r);
		else
			u = r, merge(u -> ls, l, r -> ls);
		push_up(u);
	}
	
	inline void push_front(int vl,int vr)
	{
//		printf("pf %d %d\n",vl,vr);
		merge(rt, new_Node(vl, vr), rt);
	}
	inline void insert(int k,int v)
	{
//		printf("ins %d %d\n",k,v);
		Node *l, *mid, *r;
		split_sum(rt, l, r, k + 1);
		int need = k - l -> sum;
		if(need == 0)
		{
			merge(rt, l, new_Node(v,v));
			merge(rt, rt, r);
		}
		else
		{
			split_siz(r, mid, r, 1);
			Node *nxt = new_Node(mid -> vl, mid -> vl - need + 1);
			mid -> vl -= need;
			mid -> val -= need;
			mid -> sum -= need;
			merge(rt, l, nxt);
			merge(rt, rt, new_Node(v,v));
			merge(rt, rt, mid);
			merge(rt, rt, r);
		}
	}
	
	vector<pii> vec;
	void dfs_vec(Node *u)
	{
		if(u == emp) return;
		dfs_vec(u -> ls);
		vec.push_back(make_pair(u -> vl, u -> vr));
		dfs_vec(u -> rs);
	}
} using namespace Treap;

int a[MAXN], b[MAXN];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i) scanf("%d%d",&a[i],&b[i]);
	
	a[0] = 0; a[++m] = n + 1;
	init();
	for(int i=1; i<=m; ++i)
	{
		if(a[i] - 1 > a[i-1])
			push_front(a[i]-1, a[i-1]+1);
		if(i != m) insert(a[i] - b[i], a[i]);
	}
	
	vec.clear();
	dfs_vec(rt);
	
//	for(int i=0; i<(int)vec.size(); ++i)
//	{
//		printf("vec: %d %d\n",vec[i].first,vec[i].second);
//	}
	
	int cnt = 0;
	for(int i=0,j=0; i<(int)vec.size(); i=j)
	{
		j = i+1;
		while(j<(int)vec.size() && vec[j].first < vec[j-1].second) ++j;
		++cnt;
	}
	
//	printf("cnt = %d\n",cnt);
	printf("%lld\n",C(2 * n - cnt, n));
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXF; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXF-1] = pw(fac[MAXF-1], mod - 2);
	for(int i=MAXF-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}