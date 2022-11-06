#include <iostream>
#include <cstdio>

#define MAXN 4010

using namespace std;

const int len = 86400;

int t[MAXN+1], d[MAXN+1];
int pd[2][len+1];

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &t[i], &d[i]);
        t[i]--;
    }
    t[n] = len; d[n] = 0;

    int ret = 0;
    int now = 0, next = 1;

    for (int j = 0; j <= len; j++)
        pd[now][j] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < t[i]; j++)
            if (pd[now][j] <= k)
                ret = max(ret, t[i]-j);
            
        for (int j = 0; j <= len; j++)
            pd[next][j] = pd[now][j]+1;

        if (t[i]+d[i] <= len) {
            for (int j = 0; j <= t[i]; j++)
                pd[next][t[i]+d[i]] = min(pd[next][t[i]+d[i]], pd[now][j]);
            for (int j = t[i]+1; j+d[i] <= len; j++)
                pd[next][j+d[i]] = min(pd[next][j+d[i]], pd[now][j]);
        }

        swap(now, next);
    }
    
    printf("%d\n", ret);

    return 0;
}