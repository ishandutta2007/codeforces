#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;

typedef long long ll;


#include <functional>


long long best = 1000000000000000000LL;
vector< vector<int> > g;

int n;
int sz[510000];

const ll is_query = -(1LL << 62);
 
struct Line {
    ll m, b;
    mutable function<const Line *()> succ;
 
    bool operator<(const Line &rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line *s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
 
struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b) * (z->m - y->m) >= (y->b - z->b) * (y->m - x->m);
    }
 
    void insert_line(ll m, ll b) {
        auto y = insert({m, b});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
 
    ll eval(ll x) {
        auto l = *lower_bound((Line) {x, is_query});
        return l.m * x + l.b;
    }
};

int dfs_sz(int v, int p) {
	sz[v] = 1;
	for (int x : g[v]) if (x != p) {
		sz[v] += dfs_sz(x,v);
	}
	return sz[v];
}

long long P(long long n) {
	return (n*(n-1))/2;
}

long long dfs(int v, int p) {
	HullDynamic h;

	long long ans = P(sz[v]);

	bool f = true;
	for (int x : g[v]) if (x != p) {
		long long t = dfs(x,v);

		//printf("%d -> %lld\n", x, t);

		if (!f) {
			long long th = h.eval(sz[x]);

			th = -th;
			th = th + P(sz[x] + 1);
			th = th + t;
			//printf("th = %lld\n", th);
			best = min(best, th);
		}
		else f = false;
		
		h.insert_line( n - sz[x], - P(n - sz[x]) - t);

		ans = min(ans, t + P(sz[v] - sz[x]));
		best = min(best, t + P(n - sz[x]));
	}

	return ans;
}

void solve()
{
    scanf("%d", &n);
    g.resize(n);

    for (int i = 0; i < n-1; i++) {
    	int a,b;
    	scanf("%d %d", &a, &b); a--; b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    dfs_sz(0,-1);
    dfs(0,-1);

    printf("%lld\n", 2*P(n) - best);
}


#include <fstream>


int main() {


    solve();
}