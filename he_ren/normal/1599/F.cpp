#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>mod) a-=mod;}
inline int mod_add(int a,int b){ return a+b>=mod? a + b - mod: a + b;}

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

const ll inv2 = (mod + 1) / 2;

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
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
	inline int query(int l,int r){ return mod_add(query(r), mod - query(l-1));}
}sum0, sum1, sum2;

inline int calc1(ll n){ return (n * (n + 1) / 2) %mod;}
inline int calc2(ll n){ return (n * (n + 1) * (2 * n + 1) / 6) %mod;}

inline int get_res(ll s,ll d,ll n)
{
	ll res = 0;
	res += d * d %mod * calc2(n - 1) %mod;
	res += s * 2 * d %mod * calc1(n - 1) %mod;
	res += s * s %mod * n %mod;
	return res %mod;
}

struct Query
{
	int l,r,d,id;
}qry[MAXQ];
int res[MAXQ];

int a[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=Q; ++i)
	{
		scanf("%d%d%d",&qry[i].l,&qry[i].r,&qry[i].d);
		qry[i].id = i;
	}
	
	sort(qry+1,qry+Q+1,[](Query x,Query y){ return x.r < y.r;});
	
	map<int,int> lst;
	sum0.n = sum1.n = sum2.n = n;
	for(int i=1,j=1; i<=n && j<=Q; ++i)
	{
		int &t = lst[a[i]];
		if(t != 0)
		{
			sum0.update(t, mod - 1);
			sum1.update(t, mod - a[i]);
			sum2.update(t, mod - (ll)a[i] * a[i] %mod);
		}
		t = i;
		sum0.update(t, 1);
		sum1.update(t, a[i]);
		sum2.update(t, (ll)a[i] * a[i] %mod);
		
		for(; j<=Q && qry[j].r == i; ++j)
		{
			int s0 = sum0.query(qry[j].l, qry[j].r);
			int s1 = sum1.query(qry[j].l, qry[j].r);
			int s2 = sum2.query(qry[j].l, qry[j].r);
			int d = qry[j].d;
			
			ll s = s1 * pw(s0, mod - 2) %mod - (ll)(s0 - 1) * d %mod * inv2 %mod;
			s = (s %mod + mod) %mod;
			
			res[qry[j].id] = get_res(s, d, s0) == s2;
		}
	}
	
	for(int i=1; i<=Q; ++i)
		printf(res[i]? "Yes\n": "No\n");
	return 0;
}