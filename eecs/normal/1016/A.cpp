#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, a[maxn];

int main() {
    scanf("%d %d", &n, &m);
    int lst = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        printf("%d ", (a[i] + lst) / m), lst = (a[i] + lst) % m;
    }
    return 0;
}