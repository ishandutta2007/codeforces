#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// call randint() for a random integer, good for hashing
mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
    return uniform_int_distribution<int>(a, b)(randint);
}

// returns a random double from 0 to 1
inline double rand01() {
    return uniform_randint(0, INT_MAX)/double(INT_MAX);
}

// randomly and uniformly select k distinct integers in the range [0..n-1]
// runs in O(klog(n/k))
vector<int> random_sample(int k, int n) {
    vector<int> r(k);
    std::iota(r.begin(), r.end(), 0);
    double w = exp(log(rand01())/k);
    int i = k-1;
    while (i < n) {
        i += 1+floor(log(rand01())/log(1-w));
        if (i < n) {
            r[uniform_randint(0, k-1)] = i;
            w *= exp(log(rand01())/k);
        }
    }
    return r;
}

const int maxn = 100005;
ll a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int k = n/2+1;
    ll sa = 0, sb = 0;
    for (int i = 0; i < n; i++) {
        sa += a[i]; sb += b[i];
    }
    while (1) {
        ll pa = 0, pb = 0;
        auto r = random_sample(k, n);
        debug(r);
        for (auto& i : r) {
            pa += a[i]; pb += b[i];
        }
        if (2*pa > sa && 2*pb > sb) {
            cout << k << "\n";
            for (int i = 0; i < k; i++)
                cout << r[i]+1 << " \n"[i == k-1];
            return 0;
        }
    }
}