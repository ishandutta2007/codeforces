#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const int md = 998244353;

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int mul(int a, int b) {
    return (ll)a * b % md;
}

const int N = 1007;

int C[N][N];

void precalc() {
    for (int i = 0; i < N; ++i) C[i][0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            add(C[i][j], C[i - 1][j]);
            add(C[i][j], C[i - 1][j - 1]);
        }
    }
}

int get(int n, int k) {
    if (k >= N) return 0;
    return C[n][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    precalc();
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] <= 0) continue;
        for (int j = i + 1; j <= n; ++j) {
            add(dp[i], mul(dp[j], get(j - i - 1, a[i])));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) add(ans, dp[i]);
    cout << ans << '\n';
}