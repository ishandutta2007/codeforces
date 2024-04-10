#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, cnt[20000010];
int minp[20000010], prime[2000010], tot;
ll ans[20000010];
const int m = 20000000;
int main() {
    for (int i = 2; i <= m; i++) {
        if (!minp[i]) prime[++tot] = i, minp[i] = i;
        for (int j = 1; prime[j] * i <= m; j++) {
            minp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i <= tot; i++)
        for (int j = m / prime[i]; j > 0; j--) cnt[j] += cnt[j * prime[i]];
    ll aaa = 0;
    vector < int > cur;
    for (int i = 1; i <= m; i++) {
        cur.clear();
        for (int tmp = i; tmp != 1; tmp /= minp[tmp]) cur.push_back(minp[tmp]);
        for (int j = 0; j < cur.size(); j++) if (j == 0 || cur[j] != cur[j - 1]) {
            ans[i] = max(ans[i], ans[i / cur[j]] - 1ll * i / cur[j] * cnt[i]);
        }
        ans[i] += 1ll * cnt[i] * i;
        aaa = max(aaa, ans[i]);
    }
    cout << aaa << endl;
}