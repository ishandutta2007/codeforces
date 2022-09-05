#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, a[maxn], id[maxn];
set<string> S;

int main() {
    scanf("%d", &n);
    auto ans = vector<string>(n + 1, string(n, '0'));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]), id[i] = i;
    }
    sort(id, id + n, [&](int x, int y) { return a[x] > a[y]; });
    for (int $ = 0; $ < n; $++) {
        int i = id[$], j = $;
        while (a[i]--) ans[j][i] = '1', ++j %= n + 1;
    }
    printf("%d\n", ans.size());
    for (auto &s : ans) {
        assert(!S.count(s)), S.insert(s);
        printf("%s\n", s.c_str());
    }
    return 0;
}