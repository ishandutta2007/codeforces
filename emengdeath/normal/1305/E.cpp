#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 5001;
int n, m;
int f(int x) {
    return (x / 2 - 1) * (x / 2) + (x - 1) / 2 * (x & 1);
}
int main() {
    scanf("%d %d", &n, &m);
    int x = 1;
    if (f(n) < m) {
        printf("-1\n");
        return 0;
    }
    while (f(x + 1) <= m && x + 1 <= n) x ++;
    for (int i = 1; i <= x; i ++)
        printf("%d ", i);
    if (x == n) return 0;
    int y = x + x - (m - f(x)) * 2 + 1;
    printf("%d ", y);
    for (int i = x + 2; i <= n; i ++)
        printf("%d ", 100000000 + i * 10000);
    return 0;
}