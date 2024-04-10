#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

int s[N][20];

void solve() {
    int l, r;
    cin >> l >> r;

    int ans = r - l + 1;
    for(int i = 0; i < 20; i++) {
        ans = min(ans, r - l + 1 - s[r][i] + s[l - 1][i]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 20; j++) {
            s[i][j] = s[i - 1][j] + ((i >> j) & 1);
        }
    }

    int t = 1;
    cin >> t;
//
    while(t--)
        solve();
}