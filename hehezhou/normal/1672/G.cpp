#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
int n, m;
char s[2010][2010];
int fa[4010], sze[4010], sum[4010], cnt[4010];
int sum1[2010], sum2[2010], tag1[2010], tag2[2010];
int gf(int a) { return fa[a] == a ? a : fa[a] = gf(fa[a]); }
void merge(int x, int y) {
    x = gf(x), y = gf(y);
    if (x == y) {
        sze[x]++;
        return;
    }
    sum[x] ^= sum[y], sze[x] += sze[y], cnt[x] += cnt[y];
    fa[y] = x;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    if (m % 2 == 0) {
        for (int i = 1; i <= max(n, m); i++)
            for (int j = i + 1; j <= max(n, m); j++) swap(s[i][j], s[j][i]);
        swap(n, m);
    }
    int cnttt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '?') tag1[i] = tag2[j] = 1, cnttt++;
            if (s[i][j] == '1') sum1[i] ^= 1, sum2[j] ^= 1;
        }
    if (n % 2 == 0 && m % 2 == 0) {
        cout << power(2, cnttt) << endl;
    }
    else if (n % 2 == 0) {
        int need = -1;
        for (int i = 1; i <= n; i++) {
            if (tag1[i]) cnttt--;
            else {
                if (need == -1) need = sum1[i];
                if (need != sum1[i]) return cout << 0 << endl, 0;
            }
        }
        if (need == -1) cnttt++;
        cout << power(2, cnttt) << endl;
    }
    else {
        for (int i = 1; i <= n + m; i++) cnt[i] = 1, fa[i] = i;
        for (int i = 1; i <= n; i++) sum[i] = sum1[i];
        for (int i = 1; i <= m; i++) sum[i + n] = sum2[i];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (s[i][j] == '?') merge(i, j + n);
            }
        int cnt = 0, need = -1;
        for (int i = 1; i <= n + m; i++) if (fa[i] == i) {
            cnt += sze[i];
            if (::cnt[i] & 1) {
                if (need == -1) need = sum[i];
                if (need != sum[i]) return cout << 0 << endl, 0;
            }
            else if (sum[i] != 0) return cout << 0 << endl, 0;
        }
        if (need == -1) cnt++;
        cout << power(2, cnt) << endl;
    }
}