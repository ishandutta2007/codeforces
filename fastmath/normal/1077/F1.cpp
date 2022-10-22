#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5007;

void add(int i, deque <int> &q, int *a) {
    if (a[i] == -1) return;
    while (q.size() && a[q.back()] < a[i]) q.pop_back();
    q.push_back(i);
}

void del(int i, deque <int> &q, int *a) {
    if (q.size() && q.front() == i) q.pop_front();
}

int get(deque <int> &q, int *a) {
    if (q.empty()) return -1;
    else return a[q.front()];
}   

int a[MAXN];
int dp[MAXN][MAXN];

signed main() {
    #ifdef HOME 
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < MAXN; ++i) for (int j = 0; j < MAXN; ++j) dp[i][j] = -1;

    int n, k, w;
    cin >> n >> k >> w;
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (k == 1) {
        if (w == n) {
            int ans = 0;
            for (int i = 0; i < n; ++i) ans += a[i];
            cout << ans << '\n';
        }
        else {
            cout << "-1\n";
        }   
        exit(0);
    }

    for (int i = 0; i < k; ++i) {
        dp[1][i] = a[i];
    }   

    for (int i = 2; i <= w; ++i) {
        deque <int> q;
        for (int j = 0; j < n; ++j) {
            if (j - k - 1 >= 0) del(j - k - 1, q, dp[i - 1]);
            if (j - 1 >= 0) add(j - 1, q, dp[i - 1]);
            int best = get(q, dp[i - 1]);
            if (best == -1) dp[i][j] = -1;
            else dp[i][j] = best + a[j];
        }   
    }   
    
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (n - i - 1 >= k) continue;
        ans = max(ans, dp[w][i]);
    }

    cout << ans << '\n';
    return 0;
}