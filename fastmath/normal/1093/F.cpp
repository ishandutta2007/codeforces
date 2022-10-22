#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

const int MAXN = 1e5 + 7;
const int MAXK = 107;

int n, k, len;
int a[MAXN];
deque <int> dp[MAXK];
int sumx[MAXK];

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k >> len;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    sumx[0] = 1;
    int sum = 1;
    dp[0].push_back(1);
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            for (int j = 1; j <= k; ++j) {
                int t = mod(sum - sumx[j]);
                dp[j].push_front(t);
                sumx[j] = mod(sumx[j] + t);
            }   
        }
        else {
            int t = mod(sum - sumx[a[i]]);
            dp[a[i]].push_front(t);
            for (int j = 1; j <= k; ++j) {
                if (j != a[i]) {
                    sumx[j] = 0;
                    dp[j].clear();
                }   
            }
            sumx[a[i]] = mod(sumx[a[i]] + t);   
        }   

        if (i == 0) {
            sumx[0] = 0;
            dp[0].clear();
        }

        for (int j = 1; j <= k; ++j) {
            while (dp[j].size() >= len) {
                sumx[j] = mod(sumx[j] - dp[j].back());
                dp[j].pop_back();
            }   
        }   

        sum = 0;
        for (int j = 1; j <= k; ++j) {
            sum = mod(sum + sumx[j]);
        }   
    }   
    
    cout << sum << '\n';
    return 0;
}