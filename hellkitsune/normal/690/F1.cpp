#include <bits/stdc++.h>

using namespace std;

int n;
int a[10000];
int deg[10000] = {};

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        ++deg[a];
        ++deg[b];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += deg[i] * (deg[i] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}