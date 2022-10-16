#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXK = 1000;
const int MAXT = 100;
const int MOD = 1000000007;

int dp[2][1 + 2 * MAXK * MAXT], sum[2][1 + 2 * MAXK * MAXT];
int now = 0, before = 1;

void DynamicProgramming(int t, int k) {
    int middle = t * k, up = 2 * t * k, down = 0;
    dp[0][t * k] = 1;
    for (int i = middle; i <= up; i++)
        sum[0][i] = 1;
    for (int moves = 1; moves <= t; moves++) {
        swap(now, before);
        memset(dp[now], 0, sizeof(dp[now]));
        int downLimit = middle - moves * k, upLimit = middle + moves * k;
        for (int i = downLimit; i <= upLimit; i++) {
            int right = min(i + k, up), left = max(i - k, 0);
            dp[now][i] = sum[before][right];
            if (left != 0) {
                dp[now][i] -= sum[before][left - 1];
                if (dp[now][i] < 0)
                    dp[now][i] += MOD;
            }
        }
        sum[now][down] = dp[now][down];
        for (int i = down + 1; i <= up; i++) {
            sum[now][i] = sum[now][i - 1] + dp[now][i];
            if (sum[now][i] >= MOD)
                sum[now][i] -= MOD;
        }
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int a, b, k, t;
    scanf("%d%d%d%d", &a, &b, &k, &t);
    b -= a;
    a = 0;
    DynamicProgramming(t, k);
    int middle = t * k;
    int answer = 0;
    for (int i = -t * k; i <= t * k; i++) {
        int add = dp[now][middle + i];
        if (middle + i - b - 1 <= 2 * t * k)
            if (middle + i - b - 1 >= 0)
                add = (1LL * add * sum[now][middle + i - b - 1]) % MOD;
            else
                add = 0;
        else
            add = (1LL * add * sum[now][2 * t * k]) % MOD;
        answer += add;
        if (answer >= MOD)
            answer -= MOD;
    }
    printf("%d\n", answer);
    return 0;
}