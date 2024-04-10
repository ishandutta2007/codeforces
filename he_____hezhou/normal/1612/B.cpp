#include <bits/stdc++.h>
using namespace std;
int n, T, a, b;
int p[100010];
inline void rmain() {
    cin >> n >> a >> b;
    p[1] = a, p[n] = b;
    int l = 1, r = n;
    if (a > b + 1) return puts("-1"), void();
    for (int i = b + 1; i <= n; i++) if (i != a) p[++l] = i;
    for (int i = 1; i < a; i++) if (i != b) p[--r] = i;
    if (l > n / 2 || r <= n / 2) return puts("-1"), void();
    for (int i = a + 1; i < b; i++) p[++l] = i;
    for (int i = 1; i <= n; i++) printf("%d%c", p[i], " \n"[i == n]);
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) rmain();
}