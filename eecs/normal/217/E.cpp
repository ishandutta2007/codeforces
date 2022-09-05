#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;

const int maxn = 3000010;
int m, K, l[5010], r[5010];
char str[maxn], tmp[maxn];
__gnu_cxx::rope<char> ans;

int main() {
    scanf("%s %d %d", str + 1, &K, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }
    function<void(int, int)> solve = [&](int k, int len) {
        if (!k) { ans = __gnu_cxx::rope<char>(str, str + len + 1); return; }
        if (r[k] >= len) { solve(k - 1, len); return; }
        int _len = len - min(len - r[k], r[k] - l[k] + 1);
        solve(k - 1, _len);
        int p1 = l[k], p2 = l[k] + 1, p3 = 0;
        for (int i = r[k] + 1; i <= min(len, r[k] + r[k] - l[k] + 1); i++) {
            if (p2 <= r[k]) tmp[p3++] = ans[p2], p2 += 2;
            else tmp[p3++] = ans[p1], p1 += 2;
        }
        ans.insert(r[k] + 1, __gnu_cxx::rope<char>(tmp, tmp + p3));
    };
    solve(m, K);
    for (int i = 1; i <= K; i++) putchar(ans[i]);
    return 0;
}