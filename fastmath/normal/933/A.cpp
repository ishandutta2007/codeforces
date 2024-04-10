#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

const int MAXN = 2007;
const int INF = 1e9 + 7;

int a[MAXN];
int pref[MAXN];
int pst[MAXN];
int dp[MAXN][MAXN];
int dp1[MAXN][MAXN];

signed main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1){
            pref[i] = pref[i - 1] - 1;
        }
        else {
            pref[i] = pref[i - 1] + 1;
        }
    }

    for (int i = n; i >= 1; --i){
        if (a[i] == 2){
            pst[i] = pst[i + 1] - 1;
        }
        else {
            pst[i] = pst[i + 1] + 1;
        }
    }

    for (int i = 0; i < MAXN; ++i){
        for (int j = 0; j < MAXN; ++j){
            dp[i][j] = dp1[i][j] = -INF;
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int len = 0; len <= i; ++len){
            dp[i][len] = max(dp[i - 1][len], pref[i] - pref[i - len]); 
        }
    }

    for (int i = n; i >= 1; --i){
        for (int len = 0; len <= n - i + 1; ++len){
            dp1[i][len] = max(dp1[i + 1][len], pst[i] - pst[i + len]);
        }
    }

    int ans = -INF;
    for (int p = 0; p <= n; ++p){

        int left = 0;
        for (int i = 1; i <= p; ++i){
            left += (a[i] == 1);
        }

        int right = 0;
        for (int i = p + 1; i <= n; ++i){
            right += (a[i] == 2);
        }

        ans = max(ans, left + right);

        int curr = 0;
        for (int len = 1; len <= n - p; ++len){
            int pos = p + len;
            if (a[pos] == 2) {
                --curr;
            }
            else {
                ++curr;
            }
            ans = max(ans, left + right + curr + dp[p][len]);
        }

        curr = 0;
        for (int len = 1; len <= p; ++len){
            int pos = p - len + 1;
            if (a[pos] == 1){
                --curr;
            }
            else {
                ++curr;
            }
            ans = max(ans, left + right + curr + dp1[p + 1][len]);
        }
    }

    cout << ans << '\n';

    return 0;   
}