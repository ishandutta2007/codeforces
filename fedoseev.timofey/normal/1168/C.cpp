#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 7;
const int K = 19;

int dp[N][K];
const int Inf = 1e9;
int fir[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            dp[i][j] = Inf;
        }
    }

    for (int i = 0; i < N; ++i) fir[i] = N - 1;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < K; ++j) {
            if (a[i] & (1 << j)) dp[i][j] = i;
        }
        for (int j = 0; j < K; ++j) {
            if (a[i] & (1 << j)) continue;
            for (int k = 0; k < K; ++k) {
                if (!(a[i] & (1 << k))) continue;
                for (int t = 0; t < K; ++t) {
                    if (((1 << k) | (1 << t)) >= N) continue;
                    dp[i][j] = min(dp[i][j], dp[fir[(1 << k) | (1 << t)]][j]);
                }
            }
        }

        for (int j = 0; j < K; ++j) {
            if (!(a[i] & (1 << j))) continue;
            for (int k = 0; k < K; ++k) {
                if (!(a[i] & (1 << k))) continue;
                fir[(1 << j) | (1 << k)] = i;
            }
        }    
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        bool fl = false;
        for (int i = 0; i < K; ++i) {
            if (a[y] & (1 << i)) {
                fl |= (dp[x][i] <= y);
            }
        }
        cout << (fl ? "Shi" : "Fou") << '\n';
    }
}