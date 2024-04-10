#include <cstdio>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXN = 300010;
const long long INF = 1000000000000000000LL;

long long v[MAXN], leftSum[MAXN], rightSum[MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &v[i]);
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
        leftSum[i] = leftSum[i - 1] + v[i] - v[1];
    for (int i = n; i >= 1; i--)
        rightSum[i] = rightSum[i + 1] + v[n] - v[i];
    long long answer = INF;
    int where = 0;
    for (int i = 1; i <= n; i++) {
        long long current = leftSum[n] - leftSum[i] - 1LL * (n - i) * (v[i] - v[1]);
        current = current + rightSum[1] - rightSum[i] - 1LL * (i - 1) * (v[n] - v[i]);
        if (current < answer) {
            answer = current;
            where = v[i];
        }
    }
    printf("%d", where);
    return 0;
}