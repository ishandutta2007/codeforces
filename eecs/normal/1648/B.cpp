#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int T, n, C, a[maxn], sum[maxn];
bool mark[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &C);
        fill(sum + 1, sum + C + 1, 0);
        fill(mark + 1, mark + C + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[a[i]]++, mark[a[i]] = 1;
        }
        for (int i = 1; i <= C; i++) {
            sum[i] += sum[i - 1];
        }
        bool flag = 1;
        for (int i = 1; i <= C; i++) if (mark[i]) {
            for (int j = i; j <= C; j += i) {
                if (sum[min(C, j + i - 1)] > sum[j - 1]) flag &= mark[j / i];
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}