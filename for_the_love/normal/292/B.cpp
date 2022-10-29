#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x, y, i, d[100005], c[100005];
int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        d[x]++; d[y]++;
    }
    for (i = 1; i <= n; i++)
    c[d[i]]++;
    if (c[2] == n) printf("ring topology\n");
    else
    if (c[2] == n - 2 && c[1] == 2) printf("bus topology\n");
    else
    if (c[n - 1] == 1 && c[1] == n - 1) printf("star topology\n");
    else printf("unknown topology\n");

}