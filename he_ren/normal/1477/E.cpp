#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int maxa = 1e6;
const int MAXA = maxa + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

template<typename T>
struct BIT
{
	T tree[MAXA];
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,T k)
	{
		++x;
		while(x<MAXA)
			tree[x] += k,
			x += lowbit(x);
	}
	inline T query(int x)
	{
		++x;
		T res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline T query(int l,int r){ return l>r? 0: query(r) - query(max(l-1, -1));}
};

int a[MAXN], b[MAXM];

multiset<int> sa,sb;
BIT<ll> suma, sumb;
BIT<int> cnta, cntb;

inline ll query_a(int x)
{
	if(x >= maxa) return 0;
	return suma.query(x+1,maxa) - (ll)x * cnta.query(x+1,maxa);
}
inline ll query_b(int x)
{
	if(x >= maxa) return 0;
	return sumb.query(x+1,maxa) - (ll)x * cntb.query(x+1,maxa);
}

inline ll get_res(int beg,int k,int mn)
{
	int x = beg - k;
	return query_a(min(mn, x)) - query_b(x) - (beg - min(mn, x)) + k;
}

int main(void)
{
	int n,m,Q;
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i)
		sa.insert(a[i]), suma.update(a[i],a[i]), cnta.update(a[i],1);
	for(int i=1; i<=m; ++i)
		sb.insert(b[i]), sumb.update(b[i],b[i]), cntb.update(b[i],1);
	
	while(Q--)
	{
		int oper;
		scanf("%d",&oper);
		if(oper == 1)
		{
			int pos, x;
			scanf("%d%d",&pos,&x);
			sa.erase(sa.find(a[pos])); suma.update(a[pos],-a[pos]); cnta.update(a[pos],-1);
			a[pos] = x;
			sa.insert(x); suma.update(x,x); cnta.update(x,1);
			continue;
		}
		if(oper == 2)
		{
			int pos, x;
			scanf("%d%d",&pos,&x);
			sb.erase(sb.find(b[pos])); sumb.update(b[pos],-b[pos]); cntb.update(b[pos],-1);
			b[pos] = x;
			sb.insert(x); sumb.update(x,x); cntb.update(x,1);
			continue;
		}
		
		int k;
		scanf("%d",&k);
		ll ans = -linf;
		
		int mn = min(*sa.begin(), *sb.begin()), x;
		
		x = *sb.rbegin() - k;
		ans = max(ans, query_a(min(x, mn)) - query_b(x));
		
		x = mn - k;
		ans = max(ans, query_a(x) - query_b(x));
		
		multiset<int>::iterator it = sa.lower_bound(*sb.rbegin() + k);
		if(it != sa.end())
			ans = max(ans, get_res(*it, k, mn));
		if(it != sa.begin())
			ans = max(ans, get_res(*--it, k, mn));
		
		printf("%lld\n",ans);
	}
	return 0;
}