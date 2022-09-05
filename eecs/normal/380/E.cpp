#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, a[maxn], ord[maxn], rk[maxn], tmp1[maxn], tmp2[maxn];
double ans, pw[maxn];
vector<int> pre[maxn], suf[maxn];

int main() {
    scanf("%d", &n);
    for (int i = pw[0] = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pw[i] = pw[i - 1] / 2;
    }
    /* for (int i = 1; i <= n; i++) {
        vector<double> V;
        for (int j = i; j <= n; j++) {
            V.push_back(a[j]);
            sort(V.begin(), V.end());
            double x = 0;
            for (double y : V) x = (x + y) / 2;
            ans += x;
        }
    } */
    iota(ord + 1, ord + n + 1, 1);
    sort(ord + 1, ord + n + 1, [&](int x, int y) {
        return make_pair(a[x], x) < make_pair(a[y], y);
    });
    for (int i = 1; i <= n; i++) {
        rk[ord[i]] = i;
        pre[i].push_back(i), suf[i].push_back(i);
    }
    set<int> S;
    for (int i = n; i; i--) {
        auto it = S.lower_bound(ord[i]);
        for (int $ = 1; $ <= 40; $++) {
            if (it == S.begin()) break;
            it--, pre[ord[i]].push_back(*it);
        }
        it = S.lower_bound(ord[i]);
        for (int $ = 1; $ <= 40; $++) {
            if (it == S.end()) break;
            suf[ord[i]].push_back(*it), it++;
        }
        S.insert(ord[i]);
    }
    for (int i = 1; i <= n; i++) {
        double s1 = 0, s2 = 0;
        for (int j = 0; j < pre[i].size(); j++) {
            tmp1[j] = pre[i][j] - (j + 1 == pre[i].size() ? 0 : pre[i][j + 1]);
            s1 += tmp1[j] * pw[j];
        }
        for (int j = 0; j < suf[i].size(); j++) {
            tmp2[j] = (j + 1 == suf[i].size() ? n + 1 : suf[i][j + 1]) - suf[i][j];
            s2 += tmp2[j] * pw[j];
        }
        ans += a[i] * s1 * s2 / 2;
    }
    printf("%.10f\n", ans / n / n);
    return 0;
}