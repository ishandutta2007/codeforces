#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int mod = int(1e9)+7;
vector<int>vt[8];
int dp[10005][8];
int mp[10005];
int ocp[10005];
int n, cx, cy;

void pre() {
    vt[0].push_back(7);
    vt[1].push_back(6);
    vt[2].push_back(5);
    vt[3].push_back(4), vt[3].push_back(7);
    vt[4].push_back(3);
    vt[5].push_back(2);
    vt[6].push_back(7), vt[6].push_back(1);
    vt[7].push_back(6), vt[7].push_back(3), vt[7].push_back(0);
}

int cal_1() { // 
    dp[0][7] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((j & mp[i]) != j) continue;
            for (int k = 0; k < (int)vt[j].size(); ++k) {
                dp[i][j|ocp[i]] = (1LL*dp[i][j|ocp[i]] + dp[i-1][vt[j][k]])%mod;
            }
        }
    }
    return dp[n][7];
}

int cal_2() { // 
    memset(dp, 0, sizeof (dp));
    dp[0][7] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i+1 == cx) { // 
            for (int j = 0; j < 8; ++j) {
                if ((j & mp[i]) != j) continue;
                for (int k = 0; k < (int)vt[j].size(); ++k) {
                    if (!(vt[j][k] & (1 << cy-1))) continue;
                    dp[i][j|ocp[i]] = (1LL*dp[i][j|ocp[i]] + dp[i-1][vt[j][k]])%mod;
                }
            }
        } else if (i == cx) { // 
            for (int j = 0; j < 8; ++j) {
                if ((j & mp[i]) != j) continue;
                for (int k = 0; k < (int)vt[j].size(); ++k) {
                    if (cy==3&&(j&(1<<cy-2))&&(j&(1<<cy-3))&&(vt[j][k]&(1<<cy-2))&&(vt[j][k]&(1<<cy-3))) continue;
                    if (cy==1&&(j&(1<<cy))&&(j&(1<<cy+1))&&(vt[j][k]&(1<<cy))&&(vt[j][k]&(1<<cy+1))) continue;
                    dp[i][j|ocp[i]] = (1LL*dp[i][j|ocp[i]] + dp[i-1][vt[j][k]])%mod;
                }
            }
        } else if (i-2 == cx) { // 
            for (int j = 0; j < 8; ++j) {
                if ((j & mp[i]) != j) continue;
                for (int k = 0; k < (int)vt[j].size(); ++k) {
                    if (!(vt[j][k] & (1 << cy-1))) continue;
                    dp[i][j|ocp[i]] = (1LL*dp[i][j|ocp[i]] + dp[i-1][vt[j][k]])%mod;
                }
            }
        } else {
            for (int j = 0; j < 8; ++j) {
                if ((j & mp[i]) != j) continue;
                for (int k = 0; k < (int)vt[j].size(); ++k) {
                    dp[i][j|ocp[i]] = (1LL*dp[i][j|ocp[i]] + dp[i-1][vt[j][k]])%mod;
                }
            }
        }
    }
    return dp[n][7];
}

int main() {
    pre();
    scanf("%d", &n);
    char str[10005];
    for (int i = 1; i <= 3; ++i) {
        scanf("%s", str+1);
        for (int j = 1; j <= n; ++j) {
            mp[j] |= (int)(str[j]=='.') << (i-1);
            ocp[j] |= (int)(str[j]!='.') << (i-1);
            if (str[j] == 'O') cx = j, cy = i;
        }
    }
    printf("%d\n", (cal_1()-cal_2()+mod)%mod);
    return 0;
}