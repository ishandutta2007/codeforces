#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 500010;
const ll P = 40614208162655383, i10 = 12184262448796615;
int n, m;
ll x, pre[maxn], pret[maxn], pw[maxn], ipw[maxn], suf[maxn];
char s[maxn], t[maxn];
unordered_map<ll, int> mp;

ll mul(ll a, ll b) {
    ll c = a * b - P * ll((long double)a * b / P);
    return c < 0 ? c + P : c;
}

int main() {
    scanf("%s %s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for (int i = pw[0] = ipw[0] = 1; i <= n; i++) {
        pre[i] = (pre[i - 1] * 10 + s[i] - '0') % P;
        pw[i] = 10 * pw[i - 1] % P;
        ipw[i] = mul(i10, ipw[i - 1]);
    }
    for (int i = 1; i <= m; i++) {
        pret[i] = (pret[i - 1] * 10 + t[i] - '0') % P;
    }
    x = pret[m];
    for (int i = 1; i <= n; i++) {
        mp[mul(pre[i - 1], ipw[i - 1])] = i;
        for (int j : {i + m, i + m - 1}) if (j > i && j <= n) {
            ll r = (x - pre[j] + mul(pre[i], pw[j - i]) + P) % P;
            ll v = mul((pre[i] - r + P) % P, ipw[i]);
            if (mp.count(v)) printf("%d %d\n%d %d\n", mp[v], i, i + 1, j), exit(0);
        }
    }
    for (int i = 1; i + m - 1 <= n; i++) {
        int l = 0, r = m, len;
        while (l <= r) {
            int mid = (l + r) / 2;
            ll v = (pre[i + mid - 1] - mul(pre[i - 1], pw[mid]) + P) % P;
            v == pret[mid] ? l = (len = mid) + 1 : r = mid - 1;
        }
        int j = i + m - 1;
        ll v = (x - pre[j] + mul(pre[i - 1], pw[m]) + P) % P;
        for (int t : {m - len, m - len - 1}) if (t) {
            if (j + t <= n && (pre[j + t] - mul(pre[j], pw[t]) + P) % P == v) {
                printf("%d %d\n%d %d\n", i, j, j + 1, j + t), exit(0);
            }
        }
    }
    return 0;
}