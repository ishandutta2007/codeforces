#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, ans, a[maxn], b[maxn];
bool mark[maxn];
vector<int> V[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), V[a[i]].push_back(i);
    }
    vector<array<int, 2>> seg;
    for (int i = 1; i <= n; i++) if (V[i].size() > 1) {
        mark[V[i][0]] = mark[V[i].back()] = 1;
        b[V[i][0] + 1]++, b[V[i].back()]--;
        seg.push_back({V[i][0], V[i].back()});
    }
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
        if (!mark[i] && b[i]) ans++;
    }
    sort(seg.begin(), seg.end());
    vector<array<int, 2>> E;
    int mx = 0;
    for (auto &p : seg) {
        if (mx > p[1]) ans += 2;
        else mx = p[1], E.push_back(p);
    }
    for (int i = 0, j; i < E.size(); i = max(i + 1, j - 1)) {
        for (j = i + 1; j < E.size() && E[i][1] > E[j][0]; j++);
        ans += max(0, 2 * (j - i) - 3);
    }
    printf("%d\n", ans);
    return 0;
}