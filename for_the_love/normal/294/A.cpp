#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, i, x, y, a[105];
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        a[x - 1] += y - 1;
        a[x + 1] += a[x] - y;
        a[x] = 0;
    }
    for (i = 1; i <= n; i++) printf("%d\n", a[i]);

}