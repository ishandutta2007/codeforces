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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 998244353;

const int N = 1e5 + 7;
const int L = 200;

int dp[N][L + 1][2];

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i <= L; ++i) {
        if (a[0] == -1 || a[0] == i) dp[0][i][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        vector <int> psg(L + 1), psb(L + 1);
        for (int j = 1; j <= L; ++j) {
            psg[j] = psg[j - 1];
            add(psg[j], dp[i - 1][j][1]);
            psb[j] = psb[j - 1];
            add(psb[j], dp[i - 1][j][0]);
        }
        for (int j = 1; j <= L; ++j) {
            if (a[i] != -1 && a[i] != j) continue;
            add(dp[i][j][0], psg[j - 1]);
            add(dp[i][j][0], psb[j - 1]);
            add(dp[i][j][1], sub(psg[L], psg[j - 1]));
            add(dp[i][j][1], dp[i - 1][j][0]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= L; ++i) {
        add(ans, dp[n - 1][i][1]);
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 2; ++j) {
            cout << dp[i][j][1] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 2; ++j) {
            cout << dp[i][j][0] << ' ';
        }
        cout << '\n';
    }
    cout << '\n'; */
    cout << ans << '\n';
}