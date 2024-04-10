#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int n, tot;
int f[5002], g[5002];
char s[5002];
int remainlen[1<<12];
int mn[5002];
void update(int&s, int x){
    if (!s) s = x;
    else {
        s = min(s,x);
    }
}
int main() {
    for (int i = 1; i <  (1 << 12);  i++) {
        int x = 0;
        for (int j = 0; j < 12 ;j ++)
            if ((i >> j) & 1)
                x = j;
        for (int j = 0; j <= x; j ++)
            if (!((i >>j) & 1))
                remainlen[i] += (1 << j);
    }
    scanf("%s", s + 1);
    tot = 1;
    n = strlen(s + 1);
    mn[0] = 1;
    f[0] = 1;
    for (int i = 0; i < n ; i ++) {
        bool sig = 0;
        memset(g,0,sizeof(g));
        for (int j = 0; j < (1 << 12); j++)
            if (f[j]) {
                if (f[j] != mn[i]) continue;
                if (remainlen[j] <= n - i - j - 1) {
                    update(mn[i + 1], s[i + 1 + j] - 'a' + 1);
                    update(g[j], s[i + 1 + j] - 'a' + 1);
                    sig = 1;
                }
                for (int k = 0; k < 12 && i + (1 << k) <= n; k++)
                    if (!((j >> k) & 1))
                        f[j | (1 << k)] = f[j];
            }
        if (!sig || (f[n - i] && remainlen[n - i] == 0 && i)) break;
        for (int j = 0; j <= n; j ++)
            f[j] = g[j];
        printf("%c", mn[i + 1] + 'a' - 1);
    }
    return 0;
}