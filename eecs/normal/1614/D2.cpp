#include <bits/stdc++.h>
using namespace std;

const int maxa = 20000010;
int n, tot, cnt[maxa], pr[maxa];
long long f[maxa];

int main() {
    ios::sync_with_stdio(0), cin.tie();
    cin >> n;
    while (n--) {
        int x;
        cin >> x, cnt[x]++;
    }
    fill(pr, pr + maxa, 1);
    for (int i = 2; i < maxa; i++) {
        if (pr[i]) pr[++tot] = i;
        for (int j = 1; j <= tot && i * pr[j] < maxa; j++) {
            pr[i * pr[j]] = 0;
            if (!(i % pr[j])) break;
        }
    }
    for (int i = 1; i <= tot; i++) {
        for (int j = (maxa - 1) / pr[i]; j; j--) {
            cnt[j] += cnt[j * pr[i]];
        }
    }
    for (int i = maxa - 1; i; i--) {
        for (int j = 1; j <= tot && i * pr[j] < maxa; j++) {
            f[i] = max(f[i], f[i * pr[j]] - 1LL * i * cnt[i * pr[j]]);
        }
        f[i] += 1LL * i * cnt[i];
    }
    cout << f[1] << '\n';
    return 0;
}