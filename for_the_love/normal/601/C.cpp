#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


DB dp[101][100001], s[100001];

int x[101];

DB get(int l, int r){
    if (!l) return s[r];
    return s[r] - s[l - 1];
}

int main(){
    //freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &x[i]);
        sum += x[i];
    }
    if (m == 1){
        puts("1");
        return 0;
    }
    dp[0][0] = m - 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n * m; j++){
            if (!j) s[j] = dp[i - 1][j];
            else s[j] = s[j - 1] + dp[i - 1][j];
        }
        DB sum = 0;
        for (int j = 0; j <= n * m; j++){
            DB tmp = get(max(0, j - m), j - 1);
            if (j >= x[i]) tmp -= dp[i - 1][j - x[i]];
            dp[i][j] = tmp / (m - 1);
            sum += dp[i][j];
        }
        //cout << sum << endl;
    }
    DB ans = 0;
    for (int i = 0; i < sum; i++)
        ans += dp[n][i];
    printf("%.10f\n", ans + 1);
}