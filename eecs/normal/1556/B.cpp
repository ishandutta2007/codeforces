#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, a[maxn], c[maxn];
vector<int> V[maxn];

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
        scanf("%d", &n);
        V[0].clear(), V[1].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), a[i] %= 2;
            V[a[i]].push_back(i);
        }
        if (abs((int)V[0].size() - (int)V[1].size()) > 1) {
            puts("-1"); continue;
        }
        vector<int> p;
        auto calc = [&](vector<int> p) {
            fill(c, c + n + 1, 0);
            long long ans = 0;
            for (int i = 0; i < n; i++) {
                ans += i - sum(p[i]), add(p[i], 1);
            }
            return ans;
        };
        long long ans = LLONG_MAX;
        if (V[0].size() < V[1].size()) {
            p.push_back(V[1][0]);
            for (int i = 0; i < V[0].size(); i++) {
                p.push_back(V[0][i]);
                p.push_back(V[1][i + 1]);
            }
            ans = calc(p);
        } else if (V[0].size() > V[1].size()) {
            p.push_back(V[0][0]);
            for (int i = 0; i < V[1].size(); i++) {
                p.push_back(V[1][i]);
                p.push_back(V[0][i + 1]);
            }
            ans = calc(p);
        } else {
            for (int i = 0; i < V[0].size(); i++) {
                p.push_back(V[0][i]);
                p.push_back(V[1][i]);
            }
            ans = calc(p), p.clear();
            for (int i = 0; i < V[0].size(); i++) {
                p.push_back(V[1][i]);
                p.push_back(V[0][i]);
            }
            ans = min(ans, calc(p));
        }
        printf("%lld\n", ans);
    }
    return 0;
}