#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 4005, mk = 805;
const int inf = 0x3f3f3f3f;

int n, k;
int w[ms][ms], dpold[ms], dp[ms], c[ms][ms];

void compute(int l, int r, int optl, int optr) {
    if(l>r) return;
    int mid = (l+r)/2;
    pair<int, int> best = {inf, -1};
    for(int k = optl; k <= min(mid, optr); k++) {
        best = min(best, {dpold[k-1] + c[k][mid], k});
    }
    dp[mid] = best.first;
    int opt = best.second;
    compute(l, mid-1, optl, opt);
    compute(mid+1, r, opt, optr);
}

ll solve() {
    dp[0] = 0;
    for(int i = 1; i <= n; i++) dp[i] = inf; // initialize row 0 of the dp
    for(int i = 1; i <= k; i++) {
        swap(dpold, dp);
        compute(0, n, 0, n); // solve row i of the dp
    }
    return dp[n]; // return dp[k][n]
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char ch = '#';
            while(!isdigit(ch)){
                ch = getchar();
            }
            w[i][j] = w[i][j-1] + w[i-1][j] - w[i-1][j-1];
            if(j > i) w[i][j] += ch - '0';
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
          int k = max(i-1, 0);
          c[i][j] = (w[j][j] - w[k][j] - w[j][k] + w[k][k]);
        }
    }
    cout << solve() << '\n';
}