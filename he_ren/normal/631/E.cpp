#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ldb;
const int MAXN = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Convex_Hull
{
	struct Line
	{
		bool type;
		int k;
		ll b;
		mutable ldb x;
		Line(void){}
		Line(int k,ll b): type(0), k(k), b(b), x(linf) {}
		Line(ldb x): type(1), x(x) {}
		
		inline bool operator < (const Line &oth) const
		{
			if(type || oth.type) return x < oth.x;
			return k == oth.k? b > oth.b: k < oth.k;
		}
	};
	
	inline ldb inter(const Line &p,const Line &q) const { return (ldb)(p.b - q.b) / (q.k - p.k);}
	
	multiset<Line> t;
	typedef multiset<Line>::iterator Iter;
	
	inline void clear(void){ t.clear();}
	
	inline ldb inter(const Iter &p,const Iter &q) const { return (ldb)(p -> b - q -> b) / (q -> k - p -> k);}
	
	inline Iter prev(Iter it) const { return --it;}
	inline Iter next(Iter it) const { return ++it;}
	inline bool has_prev(const Iter &it) const { return it != t.begin();}
	inline bool has_next(const Iter &it) const { return it != t.end() && next(it) != t.end();}
	
	inline bool bad(const Iter &it) const
	{
		return has_prev(it) && has_next(it) && inter(prev(it), it) >= inter(prev(it), next(it));
	}
	inline bool check_bad(const Iter &it){ return bad(it)? t.erase(it), 1: 0;}
	
	void insert(int k,ll b)
	{
		Iter it = t.insert(Line(k,b));
		
		if(has_prev(it) && prev(it) -> k == k){ t.erase(it); return;}
		if(has_next(it) && next(it) -> k == k){ t.erase(next(it)); return;}
		if(check_bad(it)) return;
		
		while(has_prev(it) && check_bad(prev(it)));
		while(has_next(it) && check_bad(next(it)));
		
		if(has_prev(it))
			prev(it) -> x = inter(prev(it), it);
		if(has_next(it))
			it -> x = inter(it, next(it));
	}
	
	inline ll query(ll x)
	{
		Iter it = t.lower_bound(Line(x));
		return it -> k * x + it -> b;
	}
};

int a[MAXN];
ll sum[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	ll ans = 0;
	
	Convex_Hull hull;
	for(int i=1; i<=n; ++i)
	{
		hull.insert(a[i], sum[i] - (ll)i * a[i]);
		
		ans = max(ans, hull.query(i) - sum[i]);
	}
	
	hull.clear();
	for(int i=n; i>=1; --i)
	{
		hull.insert(a[i], sum[i-1] - (ll)i * a[i]);
		
		ans = max(ans, hull.query(i) - sum[i-1]);
	}
	
	for(int i=1; i<=n; ++i)
		ans += (ll)i * a[i];
	printf("%lld",ans);
	return 0;
}