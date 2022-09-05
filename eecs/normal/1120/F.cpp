#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, c, d, t[maxn];
char ch[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> c >> d;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> ch[i];
    }
    cin >> t[n + 1];
    long long ans = 1LL * d * n, cur = 0;
    for (int i = n, lst; i; i--) {
        if (ch[i] != ch[i + 1]) lst = t[i + 1];
        else cur -= max(0, c * (lst - t[i + 1]) - d);
        cur += c * (lst - t[i]);
        ans = min(ans, cur + 1LL * (i - 1) * d);
    }
    cout << ans << '\n';
    return 0;
}