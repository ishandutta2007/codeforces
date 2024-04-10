#include<cstdio>
#include<cassert>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int MAXD = 2e3 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ if((a+=b)>=mod) a-=mod;}

struct Solver
{
	set<pii> t;
	int res;
	Solver(void): res(0) {}
	
	inline int chose2(int l,int r){ return l>r? 0: ((ll)(r-l+1) * (r-l+1 + 1) / 2) %mod;}
	
	inline void update(set<pii>::iterator it, int k)
	{
		set<pii>::iterator pre = it, nxt = it;
		++nxt;
		
		if(it != t.begin())
			--pre,
			res = (res - (ll)k * chose2(it -> first, -pre -> second)) %mod;
		
		if(nxt != t.end())
			res = (res - (ll)k * chose2(nxt -> first, -it -> second)) %mod;
		
		if(it != t.begin() && nxt != t.end())
			res = (res + (ll)k * chose2(nxt -> first, -pre -> second)) %mod;
		
		res = (res + (ll)k * chose2(it -> first, -it -> second)) %mod;
		
		if(res < 0) res += mod;
	}
	inline int query(void){ return res;}
	inline void erase(set<pii>::iterator it)
	{
		update(it, -1);
		t.erase(it);
	}
	inline void insert(int l,int r)
	{
		if(l>r) return;
		pii cur = make_pair(l,-r);
		set<pii>::iterator it = t.lower_bound(cur);
		
		while(it != t.end() && -it -> second <= r)
			erase(it), it = t.lower_bound(cur);
		if(it != t.begin() && -((--it) -> second) >= r) return;
		
		update(t.insert(cur).first, 1);
	}
};

struct Node
{
	int x,y,clr;
}p[MAXN];

inline bool cmp_x(const Node &p,const Node &q){ return p.x < q.x;}

int main(void)
{
	int n,d,L;
	scanf("%d%d%d",&n,&d,&L);
	for(int i=1; i<=n; ++i)
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].clr),
		++p[i].x, ++p[i].y;
	
	sort(p+1,p+n+1,cmp_x);
	p[n+1].x = L+1;
	
	ll tot = ((ll)L * (L+1) / 2) %mod;
	
	ll ans = 0;
	for(int k=1; k<=n; ++k) if(p[k].x != p[k+1].x)
	{
		static multiset<int> t[MAXD];
		for(int i=1; i<=d; ++i)
			t[i].clear(),
			t[i].insert(0), t[i].insert(L+1);
		for(int i=1; i<=k; ++i)
			t[p[i].clr].insert(p[i].y);
		
		Solver solver;
		
		bool flag = 1;
		for(int i=1; i<=d; ++i)
		{
			if((int)t[i].size() <= 2){ flag = 0; break;}
			
			multiset<int>::iterator it = t[i].begin();
			while(*it <= L)
			{
				int l = *it+1;
				++it;
				solver.insert(l,*it-1);
			}
		}
		if(!flag) continue;
		
		for(int i=1; i<=k; ++i)
		{
			if(p[i].x != p[i-1].x)
			{
				ll res = (tot + mod - solver.query()) %mod;
				if(!res) break;
				ans = (ans + res * (p[k+1].x - p[k].x) %mod * (p[i].x - p[i-1].x)) %mod;
			}
			
			multiset<int> &tt = t[p[i].clr];
			multiset<int>::iterator it = tt.lower_bound(p[i].y), pre = it, nxt = it;
			--pre; ++nxt;
			tt.erase(it);
			
			solver.insert(*pre+1, *nxt-1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}