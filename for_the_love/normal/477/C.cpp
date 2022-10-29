#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;


const DB eps = 1e-8;
const int N = 1e7 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int dp[2005][2005], ans[2005];
char s[2005], t[2005];

PI p[2005];


int main(){
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= n; i++){
        int j = i, k = 1, cnt = 0;
        while (k <= m && j <= n){
            if (s[j] == t[k]) k++; else cnt++;
            j++;
        }
        if (k == m + 1) p[i] = MP(j - 1, cnt); else p[i] = MP(-1, -1);
    }

    memset(dp, 0x7f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= n / m; j++)
        if (dp[i][j] < INF){
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (p[i + 1].first != -1)
                dp[p[i + 1].first][j + 1] = min(dp[p[i + 1].first][j + 1], dp[i][j] + p[i + 1].second);
        }
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n / m; j++)
    if (dp[i][j] < INF) ans[dp[i][j]] = max(ans[dp[i][j]], j);

    for (int i = 0; i <= n; i++){
        int l = n - ans[i] * m - i;
        if (l) ans[i + 1] = max(ans[i + 1], ans[i]);
        else ans[i + 1] = max(ans[i +1], ans[i] - 1);
    }

    for (int i = 0; i <= n; i++) printf("%d ", ans[i]);

}