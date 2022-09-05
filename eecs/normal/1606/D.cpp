#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int T, n, m, a[maxn], ord[maxn];
int mnr[maxn], mxr[maxn], mnb[maxn], mxb[maxn];
int _mnr[maxn], _mxr[maxn], _mnb[maxn], _mxb[maxn];
multiset<int> S[maxn];
char ans[maxn];

int id(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++) {
            mnr[i] = INT_MAX, mxr[i] = 0, S[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[id(i, j)]), S[j].insert(a[id(i, j)]);
            }
        }
        iota(ord + 1, ord + n + 1, 1);
        sort(ord + 1, ord + n + 1, [&](int x, int y) { return a[id(x, 1)] > a[id(y, 1)]; });
        fill(ans + 1, ans + n + 1, 'B'), ans[n + 1] = '\0';
        for (int $ = 1; $ < n; $++) {
            int i = ord[$];
            ans[i] = 'R';
            for (int j = 1; j <= m; j++) {
                mnr[j] = _mnr[j] = min(mnr[j], a[id(i, j)]);
                mxr[j] = _mxr[j] = max(mxr[j], a[id(i, j)]);
                S[j].erase(S[j].find(a[id(i, j)]));
                mnb[j] = _mnb[j] = *S[j].begin();
                mxb[j] = _mxb[j] = *S[j].rbegin();
            }
            for (int j = 2; j <= m; j++) {
                _mnr[j] = min(_mnr[j], _mnr[j - 1]);
                _mxb[j] = max(_mxb[j], _mxb[j - 1]);
            }
            for (int j = m - 1; j; j--) {
                _mxr[j] = max(_mxr[j], _mxr[j + 1]);
                _mnb[j] = min(_mnb[j], _mnb[j + 1]);
            }
            for (int j = 1; j < m; j++) {
                if (_mnr[j] > _mxb[j] && _mnb[j + 1] > _mxr[j + 1]) {
                    puts("YES");
                    printf("%s %d\n", ans + 1, j); goto done;
                }
            }
        }
        puts("NO"); done:;
    }
    return 0;
}