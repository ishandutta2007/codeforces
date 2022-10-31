#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define SZ(x)(int((x).size()))
#define ALL(x)(x).begin(), (x).end()

template <typename T> inline bool chkmin(T & a,
    const T & b) {
    return b < a ? a = b, 1 : 0;
}
template <typename T> inline bool chkmax(T & a,
    const T & b) {
    return a < b ? a = b, 1 : 0;
}

typedef long long LL;

const LL infinity = 0x3f3f3f3f3f3f3f3f;
const LL mod = 1e9 + 7;
const int M = 4e5 + 5;

int p[M];
int r[M];

LL power(LL x, LL y) {
    LL val = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) {
            val = (val * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return val;
}

struct DSU {
    int find(int n) {
        while (p[n] != n) {
            p[n] = p[p[n]];
            n = p[n];
        }
        return n;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return 0;
        } else if (r[x] > r[y]) {
            p[y] = x;
        } else if (r[y] > r[x]) {
            p[x] = y;
        } else {
            p[y] = x;
            r[x]++;
        }
        return 1;
    }

    void make_set(int n) {
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            r[i] = 0;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    DSU ds;
    ds.make_set(n);
    for (int i = 0; i < n; i++) {
        ds.merge(a[i], b[i]);
    }
    map <int, int> m;
    for (int i = 1; i <= n; i++)
        m[ds.find(i)]++;
    int sz = SZ(m);
    LL answer = power(2LL, sz);
    cout << answer << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}