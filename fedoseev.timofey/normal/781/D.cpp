#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 500;
const int K = 60;

struct matrix {
    bitset <N> a[N];
    matrix() {
        for (int i = 0; i < N; ++i) a[i].reset();
    }
};

matrix mul(const matrix &a, const matrix &b) {
    matrix c;
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            if (a.a[i][k]) {
                c.a[i] |= b.a[k];
            }
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <matrix> fir(K), sec(K);
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        if (t == 0) fir[0].a[u][v] = 1;
        else sec[0].a[u][v] = 1;
    }
    for (int i = 1; i < K; ++i) {
        fir[i] = mul(fir[i - 1], sec[i - 1]);
        sec[i] = mul(sec[i - 1], fir[i - 1]);
    }
    ll ans = 0;
    bitset <N> can;
    can[0] = 1;
    for (int i = K - 1; i >= 0; --i) {
        ll cans = ans + (1ll << i);
        matrix &cr = (__builtin_popcountll(cans) & 1 ? fir[i] : sec[i]);
        bitset <N> ncan;
        for (int j = 0; j < n; ++j) {
            if (can[j]) {
                ncan |= cr.a[j];
            }
        }
        if (ncan.count()) {
            ans = cans;
            can = ncan;
        }
    }
    if (ans > (ll)1e18) {
        cout << "-1\n";
    }
    else {
        cout << ans << '\n';
    }
}