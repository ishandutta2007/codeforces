#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int n, m;
int a[111], b[111];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(b + 1, b + m + 1);
    int t = max(a[n], a[1] * 2);
    if (t >= b[1]) puts("-1"); else printf("%d\n", t);
}