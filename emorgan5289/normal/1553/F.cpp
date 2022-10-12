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

int ceildiv(int x, int y) {
    return x == 0 ? 0 : (x-1)/y+1;
}

const ll N = 3e5+5, B = 1000;
fenwick_multiset<N, ll> f1, f2;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> a(n), p(n), cnt(N, 0);
    ll ss = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            p[i] += p[i-1];
            ll r = N;
            // debug(a[i]);
            for (ll j = 0; 1; j++) {
                ll l = max(B, a[i]/(j+1)+1);
                // debug(l, r, j);
                p[i] += a[i]*f1.count_interval(l, r)-j*f2.count_interval(l, r);
                r = l;
                if (l == B) break;
            }
            for (ll j = 1; j < B; j++)
                if (cnt[j])
                    p[i] += (a[i]%j);
            p[i] += ss;
            for (ll j = 0; a[i]*j < N; j++)
                p[i] -= a[i]*j*f1.count_interval(a[i]*j, min(N, a[i]*(j+1)));
        }
        if (i%1000 == 0) debug(i);
        f1.insert(a[i], 1);
        f2.insert(a[i], a[i]);
        cnt[a[i]]++;
        ss += a[i];
    }
    for (int i = 0; i < n; i++)
        cout << p[i] << " \n"[i == n-1];
}