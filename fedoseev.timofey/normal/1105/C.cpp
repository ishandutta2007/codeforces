#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

const int N = 2e5 + 7;

int dp[N][3];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, l, r;
    cin >> n >> l >> r;
    dp[0][0] = 1;
    vector <int> cnt(3);
    if (r - l < 100) {
        for (int i = l; i <= r; ++i) {
            ++cnt[i % 3];
        }
    }
    else {
        for (int i = 0; i < 3; ++i) {
            int nl = l;
            int nr = r;
            while ((nl % 3) != i) ++nl;
            while ((nr % 3) != i) --nr;
            cnt[i] = (nr - nl) / 3 + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                add(dp[i + 1][(j + k) % 3], mul(dp[i][j], cnt[k]));
            }
        }
    }
    cout << dp[n][0] << '\n';
}