#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[5010];
void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    printf("%d\n", a[n] + a[n - 1]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}