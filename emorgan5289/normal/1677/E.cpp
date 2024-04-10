#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// ordered statistic tree using fenwick tree.
// all operations take O(log(N)),
// where N is the limit on size of elements.
// see https://codeforces.com/blog/entry/61364

template<int N, typename T = int>
struct fenwick_multiset {

    T s = 0, tree[N+1];
    T size() const { return s; }
    fenwick_multiset() { fill(tree, tree+N+1, 0); }
    
    // insert x into the set with multiplicity k
    void insert(int x, const T k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const T k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    T index(int x) const {
        if (x <= 0) return 0;
        if (x >= N) return size();
        T i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    T count_lower(int x) const {
        return index(x);
    }

    T count_greater(int x) const {
        return size()-index(x+1);
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    T count(int x) const {
        if (x < 0 || x >= N) return 0;
        int y = x+1; T i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(T x) const {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }

    // returns the largest element of the set
    // which is < x, or -1 if no such element
    int next_lower(int x) {
        T i = index(x);
        return i == 0 ? -1 : get(i-1);
    }

    // returns the smallest element of the set
    // which is > x, or N if no such element
    int next_greater(int x) {
        return get(index(x+1));
    }

    // returns the number of values in the set
    // in the semi-open interval [l, r)
    T count_interval(int l, int r) {
        return index(r)-index(l);
    }
};

const int N = 1e6+5;
fenwick_multiset<N, ll> vx, vy, o, oo;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;
    vector<ll> p(n), pi(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i], p[i]--;
        pi[p[i]] = i;
    }
    debug(p);
    debug(pi);

    vector<array<ll, 2>> sub(n);
    set<int> s;
    s.insert(-1);
    s.insert(n);
    for (int i = n-1; i >= 0; i--) {
        sub[i][0] = *--s.lower_bound(pi[i])+1;
        sub[i][1] = *s.lower_bound(pi[i])-1;
        s.insert(pi[i]);
    }

    debug(sub);

    vector<vector<array<ll, 2>>> ival(n);

    for (ll i = 0; i < n; i++) {
        for (ll j = i+1; (j+1)*(i+1) <= n; j++) {
            int k = (j+1)*(i+1)-1;
            // debug(i, j, k);

            ll l = min({pi[i], pi[j], pi[k]});
            ll r = max({pi[i], pi[j], pi[k]});

            if (l < sub[k][0] || r > sub[k][1])
                continue;
            ival[k].pb({l, -r});
        }
    }

    // debug(ival);

    vector<array<ll, 4>> gb_ival;

    for (int k = 0; k < n; k++) {
        sort(all(ival[k])); // O(nlog^2n) ?
        vector<array<ll, 2>> tmp;
        for (auto& [l, r] : ival[k]) {
            r *= -1;
            while (!tmp.empty() && r <= tmp.back()[1])
                tmp.pop_back();
            tmp.pb({l, r});
        }
        ll pl = sub[k][0]-1, pr = sub[k][1]+1;
        for (auto& [l, r] : tmp) {
            debug(k, l, r);
            gb_ival.pb({pl+1, l, r, pr-1});
            pl = l;
        }
    }

    debug(gb_ival);

    vector<array<ll, 2>> qry(q);
    for (int i = 0; i < q; i++) {
        cin >> qry[i][0] >> qry[i][1];
        qry[i][0]--, qry[i][1]--;
    }

    debug(qry);

    vector<vector<array<ll, 3>>> ev(N);
    for (auto& [xl, xr, yl, yr] : gb_ival) {
        xl++, xr++, yl++, yr++;
        ev[xr+1].pb({xr, yl, 1});
        ev[xr+1].pb({xr, yr+1, -1});
        ev[xl].pb({xl-1, yl, -1});
        ev[xl].pb({xl-1, yr+1, 1});
    }

    vector<vector<array<ll, 3>>> qq(N);
    for (int i = 0; i < q; i++) {
        auto& [l, r] = qry[i];
        l++, r++;
        qq[l+1].pb({l, r, i});
    }

    vector<ll> ans(q);

    for (int i = N-1; i >= 0; i--) {
        if (ev[i].size() || qq[i].size()) debug(ev[i]), debug(qq[i]);
        for (auto& [x, y, d] : ev[i]) {
            o.insert(y, x*y*d);
            oo.insert(y, d);
            vx.insert(y, x*d);
            vy.insert(y, y*d);
        }
        for (auto& [x, y, j] : qq[i]) {
            ans[j] = (x-1)*(y+1)*oo.count_lower(y+1) + o.count_lower(y+1) - (x-1)*vy.count_lower(y+1) - (y+1)*vx.count_lower(y+1);
            debug(j, x, y);
            // debug(oo.sum(0, y) , o.sum(0, y) ,vy.sum(0, y),vx.sum(0, y));
        }
    }

    for (int i = 0; i < q; i++)
        cout << -ans[i] << "\n";
}