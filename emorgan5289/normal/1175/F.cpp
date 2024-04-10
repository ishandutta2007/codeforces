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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

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
        T i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    T count(int x) const {
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
};

const int N = 3e5+5;
ll a[N], f[N], j = 0;
deque<ll> p;
fenwick_multiset<N> s;

void upd(int k) {
    int i = p.size() == 1 ? j-1 : p[p.size()-2], x = p.back();
    s.insert(i+a[x], k), s.remove(x+a[x], k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        f[a[i]]++;
        while (!p.empty() && a[p.back()] <= a[i])
            upd(-1), p.pop_back();
        p.pb(i), upd(1);
        while (f[a[i]] > 1) {
            int x = j-1+a[p[0]];
            s.remove(x), s.insert(x+1);
            if (j == p[0]) p.pop_front();
            f[a[j++]]--;
        }
        ans += s.index(i+1);
    }
    cout << ans << "\n";
}