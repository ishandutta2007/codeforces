#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int i, j, num, tmp, x, cnt, n, ans, b[100005], p[100005], v[100005], f[100005], a[100005];
int main(){
    for (i = 2; i <= 100000; i++) if (!v[i])
    for (j = 2; j * i <= 100000; j++)
        v[i * j] = 1;
    for (i = 2; i <= 100000; i++)
    if (!v[i]) p[++cnt] = i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (n == 1 && a[1] == 1){
        printf("1\n");
        return 0;
    }
    for (i = 1; i <= n; i++){
        num = tmp = 0;
        x = a[i];
        for (j = 1; j <= cnt && p[j] * p[j] <= a[i]; j++)
        if (x % p[j] == 0){
            b[++num] = p[j];
            while (x % p[j] == 0){
                x = x / p[j];
                tmp = max(tmp, f[p[j]]);
            }
        }
        if (x != 1){
            b[++num] = x;
            tmp = max(tmp, f[x]);
        }
        for (j = 1; j <= num; j++)
            f[b[j]] = max(f[b[j]], tmp + 1);
    }
    for (i = 1; i <= 100000; i++) ans = max(ans, f[i]);
    printf("%d\n", ans);
}