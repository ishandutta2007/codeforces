#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;
const int INF = 1e16 + 7;

int n, k;
int a[MAXN], b[MAXN];
int dp[MAXN][2];

int get(int a, int b) {
    return max(1ll, a - k * (b - 1));    
}   

bool check0(int i) {
    if (!a[i]) return 0;

    if (dp[i][0] <= k) {
        return b[i] <= k * a[i];
    }   
    else {
        return b[i] <= (k - dp[i][1]) + k * (a[i] - 1);
    }   
}   

bool check1(int i) {
    if (!b[i]) return 0;

    if (dp[i][1] <= k) {
        return a[i] <= k * b[i];
    }
    else {
        return a[i] <= (k - dp[i][0]) + k * (b[i] - 1);
    }   
}   

void calc(int i) {
    if (dp[i][0] <= k) {
        int add = k - dp[i][0];
        if (b[i]) dp[i + 1][0] = min(dp[i + 1][0], get(a[i] - add, b[i]));
        else dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a[i]);

        dp[i + 1][1] = min(dp[i + 1][1], get(b[i] - k, a[i]));
    }

    if (dp[i][1] <= k) {
        dp[i + 1][0] = min(dp[i + 1][0], get(a[i] - k, b[i]));

        int add = k - dp[i][1];
        if (a[i]) dp[i + 1][1] = min(dp[i + 1][1], get(b[i] - add, a[i]));
        else dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + b[i]);
    }   
    
    if (!check0(i)) dp[i + 1][0] = INF;
    if (!check1(i)) dp[i + 1][1] = INF;
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 1; i < MAXN; ++i) dp[i][0] = dp[i][1] = INF;
    
    for (int i = 0; i < n; ++i) {
        calc(i);
        //cout << dp[i + 1][0] << ' ' << dp[i + 1][1] << '\n';
        if (k < dp[i + 1][0] && k < dp[i + 1][1]) {
            cout << "NO\n";
            exit(0);
        }   
    }

    cout << "YES\n";
    return 0;
}