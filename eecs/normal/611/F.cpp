#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 1000000007;
int n, h, w, cnt[2], fir[1000010];
char s[500010];
vector<pair<ll, int>> V;

int main() {
    scanf("%d %d %d %s", &n, &h, &w, s + 1);
    int sx = 0, sy = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'U') sx--;
        if (s[i] == 'D') sx++;
        if (s[i] == 'L') sy--;
        if (s[i] == 'R') sy++;
    }
    if (sx < 0) {
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'U') s[i] = 'D';
            else if (s[i] == 'D') s[i] = 'U';
        }
        sx *= -1;
    }
    if (sy < 0) {
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'L') s[i] = 'R';
            else if (s[i] == 'R') s[i] = 'L';
        }
        sy *= -1;
    }
    int cur = 0, mn = 0, mx = 0, B = 500000;
    memset(fir, 0x3f, sizeof(fir));
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'U') cur--;
        else if (s[i] == 'D') cur++;
        if (fir[cur + B] > n) fir[cur + B] = i;
        mn = min(mn, cur), mx = max(mx, cur);
    }
    for (int i = 1; i <= h; i++) {
        if (i + mn < 1 || i + mx > h) {
            V.emplace_back(min(fir[B - i], fir[h - i + 1 + B]), 0);
        } else {
            if (!sx) {
                V.emplace_back(LLONG_MAX, 0);
            } else {
                int t = (h - i + 1 - mx + sx - 1) / sx;
                V.emplace_back(1LL * n * t + fir[h - i + 1 - t * sx + B], 0);
            }
        }
    }
    memset(fir, 0x3f, sizeof(fir));
    cur = 0, mn = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') cur--;
        else if (s[i] == 'R') cur++;
        if (fir[cur + B] > B) fir[cur + B] = i;
        mn = min(mn, cur), mx = max(mx, cur);
    }
    for (int i = 1; i <= w; i++) {
        if (i + mn < 1 || i + mx > w) {
            V.emplace_back(min(fir[B - i], fir[w - i + 1 + B]), 1);
        } else {
            if (!sy) {
                V.emplace_back(LLONG_MAX, 1);
            } else {
                int t = (w - i + 1 - mx + sy - 1) / sy;
                V.emplace_back(1LL * n * t + fir[w - i + 1 - t * sy + B], 1);
            }
        }
    }
    sort(V.begin(), V.end(), greater<pair<ll, int>>());
    int ans = 0;
    for (auto p : V) {
        int foo = 0;
        for (int i : {0, 1}) if (i ^ p.second) foo = cnt[i];
        if (p.first > 1e18 && foo) printf("-1\n"), exit(0);
        ans = (ans + p.first % P * foo) % P, cnt[p.second]++;
    }
    printf("%d\n", ans);
    return 0;
}