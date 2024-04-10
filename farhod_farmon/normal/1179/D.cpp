#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 500500;

using namespace std;

bool Q;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};

struct LineContainer : multiset<Line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
		return l.k * x + l.m;
	}
};

int n;
long long s[N];
long long d[N];
long long f[N];
vector < int > v[N];

void calc(int x, int p)
{
        s[x] = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                calc(y, x);
                s[x] += s[y];
        }
}

void dfs(int x, int p)
{
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                d[y] = d[x] + 1ll * (s[x] - s[y]) * (s[x] - s[y] - 1);
                dfs(y, x);
        }
        f[x] = d[x];
        d[x] += 1ll * s[x] * (s[x] - 1);
        for(int y: v[x]){
                if(y != p){
                        d[x] = min(d[x], d[y]);
                }
        }
}

long long res = -4e18, cost;

void solve(int x, int p)
{
        bool good = false;
        LineContainer S;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                solve(y, x);
                cost = d[y] - f[x];
                cost -= 1ll * (s[x] - s[y]) * (s[x] - s[y] - 1);
                res = max(res, - cost - 1ll * (n - s[y]) * (n - s[y] - 1));
                if(good){
                        long long shit = 1ll * n * n - n;
                        shit += - 2ll * n * s[y];
                        shit += 1ll * s[y] * s[y] + s[y];
                        shit += cost;
                        shit = - shit;
                        res = max(res, S.query(s[y]) + shit);
                }
                long long shit = cost;
                shit += - 2ll * s[y] * n;
                shit += 1ll * s[y] * s[y] + s[y];
                shit = - shit;
                S.add(- s[y] * 2, shit);
                good = true;
        }

}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        scanf("%d", &n);
        for(int i = 1, x, y; i < n; i++){
                scanf("%d %d", &x, &y);
                v[x].push_back(y);
                v[y].push_back(x);
        }
        calc(1, 1);
        dfs(1, 1);
        solve(1, 1);
        cout << 1ll * n * (n - 1) + res / 2 << "\n";
}