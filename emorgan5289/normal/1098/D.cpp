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

    // returns the smallest element of the set
    // which is > x, or N if no such element
    int next_greater(int x) {
        return get(index(x+1));
    }

    // returns the largest element of the set
    // which is < x, or -1 if no such element
    int next_lower(int x) {
        T i = index(x);
        return i == 0 ? -1 : get(i-1);
    }

    // returns the number of values in the set
    // in the semi-open interval [l, r)
    T count_interval(int l, int r) {
        return index(r)-index(l);
    }
};

const int N = 1e6+5;
fenwick_multiset<N, ll> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> a(n), b, r(n);
    map<ll, vector<ll>> stk;
    for (int i = 0; i < n; i++) {
        char x; cin >> x >> a[i];
        if (x == '-') {
            a[i] = -a[i];
            r[i] = stk[-a[i]].back();
            stk[-a[i]].pop_back();
        } else {
            b.pb(i);
            stk[a[i]].pb(i);
        }
    }
    sort(all(b), [&](int i, int j){
        return a[i] == a[j] ? i < j : a[i] < a[j];
    });
    for (int i = 0; i < b.size(); i++)
        r[b[i]] = i;
    for (int i = 0; i < n; i++)
        if (a[i] < 0) r[i] = r[r[i]];
    debug(a);
    debug(r);

    auto check = [&](int i) {
        if (i == -1 || i == N) return false;
        return f.index(i) > 0 && 2*f.count(f.next_lower(i)) < f.count(i);
    };

    ll sz = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (check(f.next_greater(r[i])))
                s.erase(s.find(f.next_greater(r[i])));
            f.insert(r[i], a[i]);
            if (check(f.next_greater(r[i])))
                s.insert(f.next_greater(r[i]));
            if (check(r[i]))
                s.insert(r[i]);
            sz++;
        } else {
            if (check(f.next_greater(r[i])))
                s.erase(s.find(f.next_greater(r[i])));
            if (check(r[i]))
                s.erase(s.find(r[i]));
            f.insert(r[i], a[i]);
            if (check(f.next_greater(r[i])))
                s.insert(f.next_greater(r[i]));
            sz--;
        }
        ll ans = max(0ll, sz-1);
        for (auto& j : s)
            if (2*f.index(j) < f.count(j))
                ans--;
        cout << ans << "\n";
    }
}