#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
int n;
int sum[100];
int a[500000], b[500000];
long long f[500000][20];
long long ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    if (a[n] == - 1) {
        printf("0");
        return 0;
    }
    int x = 1;
    while (a[x] != -1) a[x ++] = 0;
    int step = 1;
    while ((1 << step) < n) step ++;
    for (int i = 1; i <= step; i ++)
        sum[i] = sum[i - 1] + (1 << ((step - i)));
    for (int i = 1; i <= n; i ++)
        if (i !=  x)
        b[++b[0]] = a[i];
    f[b[0]][1] = b[b[0]];
    for (int i = b[0]; i > 1; i --)
        for (int j = 1; j <= step; j ++)
            if (f[i][j]) {
                if (sum[j] >= b[0] - i + 2&&(!f[i - 1][j] || f[i - 1][j] > f[i][j]))
                    f[i - 1][j] = f[i][j];
                if (!f[i - 1][j + 1] || f[i - 1][j + 1] > f[i][j] + b[i - 1])
                    f[i - 1][j + 1] = f[i][j] + b[i - 1];
            }
    printf("%lld\n", f[1][step]);
    return 0;
}