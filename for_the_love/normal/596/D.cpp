#include <bits/stdc++.h>

using namespace std;

typedef double DB;
typedef long long LL;

const int N = 1e5 + 7;
const int INF = 1e9 + 7;


DB dp[2002][2002][2][2];

bool v[2002][2002][2][2];

int n, h, x[2002];

DB p;


DB dfs(int l, int r, int fl, int fr){
    if (l > r) return 0;
    if (v[l][r][fl][fr]) return dp[l][r][fl][fr];
    v[l][r][fl][fr] = 1;


    if (fl == 1 && x[l - 1] + h > x[l]){
        if (l == r){
            if (fr == 0) return dp[l][r][fl][fr] = min(h + h, x[l + 1] - x[l]) - min(h, x[l + 1] - x[l]);
            else return dp[l][r][fl][fr] = min(x[l + 1] - x[l], h);
        }else{
            return dp[l][r][fl][fr] = dfs(l + 1, r, 1, fr) + min(h, x[l + 1] - x[l]);
        }
    }


    if (fr == 0 && x[r + 1] - h < x[r]){
        if (l == r){
            if (fl == 1) return dp[l][r][fl][fr] = min(h + h, x[r] - x[r - 1]) - min(h, x[r] - x[r - 1]);
            else return dp[l][r][fl][fr] = min(x[r] - x[r - 1], h);
        }else{
            return dp[l][r][fl][fr] = dfs(l, r - 1, fl, 0) + min(h, x[r] - x[r - 1]);
        }
    }

    DB ret = 0;

    if (fl == 0) ret += 0.5 * p * (dfs(l + 1, r, 0, fr) + min(x[l] - x[l - 1], h));
    else ret += 0.5 * p * (dfs(l + 1, r, 0, fr) + min(x[l] - x[l - 1], 2 * h) - min(x[l] - x[l - 1], h));

    if (l != r) ret += 0.5 * (1 - p) * (dfs(l + 1, r, 1, fr) + min(x[l + 1] - x[l], h));

    if (fr == 1) ret += 0.5 * (1 - p) * (dfs(l, r - 1, fl, 1) + min(x[r + 1] - x[r], h));
    else ret += 0.5 * (1 - p) * (dfs(l, r - 1, fl, 1) + min(x[r + 1] - x[r], 2 * h) - min(x[r + 1] - x[r], h));

    if (l != r) ret += 0.5 * p * (dfs(l, r - 1, fl, 0) + min(x[r] - x[r - 1], h));

    if (l == r) ret += ret;

    return dp[l][r][fl][fr] = ret;
}


int main(){
    scanf("%d%d%lf", &n, &h, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]);

    x[0] = -INF, x[n + 1] = INF;

    sort(x + 1, x + n + 1);

    memset(v, 0, sizeof(v));

    printf("%.8f\n", dfs(1, n, 0, 1));
}