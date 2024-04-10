#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef long long ll;

ll n, ans, dp[3030][3030], a[3030];
vector<int> mask;
int f[4][4] = {{0, 0, 1, 1}, {0, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};
vector<pair<string, int>> SA;

bool can() {
    if(mask.size() < 4) return true;
    for(int i = 0; i < 4; i++) {
        int eita = 1;
        for(int j = 0; eita && j < 4; j++)
            if(mask[j] != f[i][j])
                eita = false;
        if(eita) return false;
    }
    return true;
}

ll lcp(int idx) {
    ll ans = 0, l = SA[idx].second, r = SA[idx+1].second;
    string &s1 = SA[idx].first, &s2 = SA[idx+1].first;
    for(int i = 0; i < s1.size() && i < s2.size() && s1[i] == s2[i]; i++) {
        ans += dp[l-i][l];
        if(ans >= MOD) ans -= MOD;
    }
    return ans;
}

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);

        if(i <= 4) mask.push_back(a[i]);
        else {
            for(int i = 0; i < 3; i++)
                mask[i] = mask[i+1];
            mask[3] = a[i];
        }

        dp[i][i] = dp[i][i-1] = 1;
        for(int l = 1; l < i; l++) {
            for(int j = 1; j <= min(4, i-l+1); j++) {
                if(j < 4) dp[l][i] += dp[l][i-j];
                else if(can()) dp[l][i] += dp[l][i-j];
            }
            dp[l][i] %= MOD;
        }

        string str;
        for(int l = i; l > 0; l--) str += ('0' + a[l]);
        pair<string, int> item = {str, i};
        int idx = upper_bound(SA.begin(), SA.end(), item) - SA.begin();

        if(idx > 0 && idx < SA.size()) {
            ans += lcp(idx-1);
            if(ans >= MOD) ans -= MOD;
        }

        SA.insert(SA.begin() + idx, item);
        for(int l = 1; l <= i; l++) {
            ans += dp[l][i];
            if(ans >= MOD) ans -= MOD;
        }

        if(idx > 0) {
            ans -= lcp(idx-1);
            if(ans < 0) ans += MOD;
        }
        if(idx + 1 < SA.size()) {
            ans -= lcp(idx);
            if(ans < 0) ans += MOD;
        }

        printf("%lld\n", ans);
    }

    return 0;
}