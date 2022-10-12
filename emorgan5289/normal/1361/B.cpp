#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<int N>
struct fenwick_multiset {

    int s = 0, tree[N+1] = {};
    int size() const { return s; }
    
    // insert x into the set with multiplicity k
    void insert(int x, const int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    int index(int x) const {
        int i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    int count(int x) const {
        int y = x+1, i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(int x) const {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

// returns (b^r)%m, runs in O(logr) time.
template<typename T>
T powmod(T b, T r, T m) {
    T out = 1;
    for (T t = 1; t <= r; t <<= 1) {
        if (r&t) out = (out*b)%m;
        b = (b*b)%m;
    }
    return out;
}

// returns a unique number b s.t. ab = 1 mod m in O(logm) time.
template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

// based on something from KACTL, requires 64bit C++
struct fastmod {
    __int128_t b, m;
    fastmod(int64_t x) : b(x), m(((__int128_t)1<<64) / x) {}
    int64_t reduce(int64_t x) {
        __int128_t q = (m*x)>>64;
        __int128_t r = x - q*b;
        return r >= b ? r - b : r;
    }
};

const int maxn = 1000005;
const ll mod = 1000000007;
fenwick_multiset<maxn> f;
vector<pair<ll, int>> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, p; cin >> n >> p;
        while (f.size() > 0) f.remove(f.get(0));
        for (int i = 0; i < n; i++) {
            ll a; cin >> a; f.insert(a);
        }
        s.clear();
        ll out = 0;
        if (p == 1) {
            cout << (n%2) << "\n"; continue;
        }
        while (f.size() > 0) {
            ll x = f.get(f.size()-1);
            s.clear(); f.remove(x);
            while ((s.size() == 0 || s[0].first < x) && f.size() > 0) {
                ll y = f.get(f.size()-1); f.remove(y);
                if (s.size() > 0 && s.back().first == y)
                    s.back().second++;
                else
                    s.pb({y, 1});
                while (s.back().second == p) {
                    y = s.back().first+1; s.pop_back();
                    if (s.size() > 0 && s.back().first == y)
                        s.back().second++;
                    else
                        s.pb({y, 1});
                }
            }
            if (s.size() == 0 || s[0].first != x) {
                debug(x, s);
                out = powmod(p, x, mod);
                for (auto& [y, k] : s)
                    out = (out+k*(mod-powmod(p, y, mod)))%mod;
            }
        }
        cout << out << "\n";
    }
}