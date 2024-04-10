#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 511;
int f[N][N];
int n;
int step[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &f[i][i]);
    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l + len - 1 <= n; l ++) {
            int r = l + len - 1;
            for (int mid = l; mid < r; mid ++)
                if (f[l][mid] && f[mid + 1][r] && f[l][mid] == f[mid + 1][r]) {
                    f[l][r] = f[l][mid] + 1;
                    break;
                }
        }
    }
    for (int i = 1; i <= n; i ++) {
        step[i] = i;
        for (int j = i; j >= 1; j --)
            if (f[j][i])
                step[i] = min(step[i], step[j - 1] + 1);
    }
    printf("%d\n", step[n]);
    return 0;
}