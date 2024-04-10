#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, c[maxn];
char s[maxn], t[maxn];
vector<int> V[26];

void add(int p, int v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s %s", &n, s + 1, t + 1);
        for (int i = 0; i < 26; i++) {
            V[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            V[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            reverse(V[i].begin(), V[i].end());
        }
        fill(c, c + n + 1, 0);
        long long ans = LLONG_MAX, cur = 0;
        for (int i = 1; i <= n; i++) {
            for (int c = 0; c < t[i] - 'a'; c++) if (!V[c].empty()) {
                ans = min(ans, cur + V[c].back() - 1 - sum(V[c].back()));
            }
            int c = t[i] - 'a';
            if (V[c].empty()) break;
            cur += V[c].back() - 1 - sum(V[c].back());
            add(V[c].back(), 1), V[c].pop_back();
        }
        printf("%lld\n", ans == LLONG_MAX ? -1 : ans);
    }
    return 0;
}