#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
#include <bits/stdc++.h>
using namespace std;

// code credit : https://github.com/niklasb/contest-algos/
// blob/master/convex_hull/dynamic.cpp
using line_t = long double;
const line_t is_query = -1e100;

struct Line {
	line_t m, b;
	mutable function<const Line*()> succ;
	bool operator<(const Line& rhs) const {
		if (rhs.b != is_query) return m < rhs.m;
		const Line* s = succ();
		if (!s) return 0;
		line_t x = rhs.m;
		return b - s->b < (s->m - m) * x;
	}
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
	bool bad(iterator y) {
		auto z = next(y);
		if (y == begin()) {
			if (z == end()) return 0;
			return y->m == z->m && y->b <= z->b;
		}
		auto x = prev(y);
		if (z == end()) return y->m == x->m && y->b <= x->b;
		return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
	}
	void insert_line(line_t m, line_t b) {
		auto y = insert({ m, b });
		y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
		if (bad(y)) { erase(y); return; }
		while (next(y) != end() && bad(next(y))) erase(next(y));
		while (y != begin() && bad(prev(y))) erase(prev(y));
	}
	line_t query(line_t x) {
		Line u = { x, is_query };
		auto l = *lower_bound(u);
		return l.m * x + l.b;
	}
}* solver;

int n;
vector<pair<long long,pair<long long,long long> > >vec;
long long ans;

int main(void) {
    scanf("%d",&n);
    
    for (int i = 1; i <= n; i++){
		ll X,Y,A;
		scanf("%lld%lld%lld", &X,&Y,&A);
		vec.pb(mp(X,mp(Y,A)));
	}
    SORT(vec);
    solver = new HullDynamic();
    solver->insert_line((long double)(0.0),(long double)(0.0));
    for(int j=0;j<n;j++){
    	ll cur_val = floor(solver->query((long double)(vec[j].sc.fi))+0.3);
    	cur_val += vec[j].fi*vec[j].sc.fi-vec[j].sc.sc;
    	ans = max(ans,cur_val);
    	solver->insert_line((long double)(-1LL*vec[j].fi),(long double)(cur_val));
    	//cout<<vec[j].fi<<" "<<cur_val<<endl;
	}
	printf("%lld\n", ans);
    return 0;
}