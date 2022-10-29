#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
const int N =1e5 + 1;
int a[N], c[N];
long long ans[N];
struct node{
    int g, s;
}b[N];
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i ++)
    {
        c[i] = i;
        scanf("%d", &a[i]);
    }
    sort(c + 1, c + n + 1, [](int x, int y){return a[x] < a[y];});
    for (int i = 1; i <= m ; i ++)
        scanf("%d %d", &b[i].g, &b[i].s);
    sort(b + 1, b + m + 1, [](node a, node b) {return a.g < b.g;});
    int l = 1;
    long long all = 0;
    for (int i = 1; i <= n ; i ++) {
        while (l <= m && b[l].g <= a[c[i]])all += b[l++].s;
        ans[c[i]] = all;
    }
    for (int i=  1; i <= n ; i ++)
        printf("%lld ", ans[i]);
    return 0;
}