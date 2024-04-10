#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, i, j, ans, a[500], b[500];

int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    if (i != j && a[i] == b[j]) ans++;
    printf("%d\n", ans);
}