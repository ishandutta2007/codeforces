#include <bits/stdc++.h>
using namespace std;

const int maxn = 50010;
int n, q;
char s[maxn], s1[maxn], s2[maxn];
set<int> S[550000];
map<pair<int, int>, int> mp;

int main() {
    scanf("%s %d", s + 1, &q), n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        int num = 0;
        for (int j = i; j <= min(n, i + 3); j++) {
            num = num * 26 + s[j] - 'a' + 1;
            S[num].insert(i);
        }
    }
    while (q--) {
        scanf("%s %s", s1 + 1, s2 + 1);
        int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
        int h1 = 0, h2 = 0;
        for (int i = 1; i <= len1; i++) {
            h1 = h1 * 26 + s1[i] - 'a' + 1;
        }
        for (int i = 1; i <= len2; i++) {
            h2 = h2 * 26 + s2[i] - 'a' + 1;
        }
        if (S[h1].empty() || S[h2].empty()) { puts("-1"); continue; }
        if (mp.count({h1, h2})) { printf("%d\n", mp[{h1, h2}]); continue; }
        int ans = INT_MAX;
        if (S[h1].size() > S[h2].size()) swap(h1, h2), swap(len1, len2);
        for (int p : S[h1]) {
            auto it = S[h2].lower_bound(p);
            if (it != S[h2].end()) {
                ans = min(ans, max(p + len1 - 1, *it + len2 - 1) - p + 1);
            }
            if (it != S[h2].begin()) {
                it--, ans = min(ans, max(p + len1 - 1, *it + len2 - 1) - min(p, *it) + 1);
            }
        }
        printf("%d\n", mp[{h1, h2}] = mp[{h2, h1}] = ans);
    }
    return 0;
}