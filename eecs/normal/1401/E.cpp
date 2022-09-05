#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, m, c[maxn];
long long ans;
vector<pair<int, int>> M[maxn], Q[maxn];

void add(int p, int v) {
    for (p++; p < maxn; p += p & -p) c[p] += v;
}

int sum(int p) {
    int s = 0;
    for (p++; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d %d", &n, &m);
    while (n--) {
        int x, l, r;
        scanf("%d %d %d", &x, &l, &r);
        if (!l && r == 1000000) ans++;
        M[x].emplace_back(l, r);
    }
    while (m--) {
        int x, l, r;
        scanf("%d %d %d", &x, &l, &r);
        if (!l && r == 1000000) ans++;
        Q[l - 1].emplace_back(x, -1);
        Q[r].emplace_back(x, 1);
    }
    for (int i = 1; i <= 1000000; i++) {
        for (auto p : M[i]) {
            add(p.first, 1), add(p.second + 1, -1);
        }
        for (auto p : Q[i]) {
            ans += p.second * sum(p.first);
        }
    }
    printf("%lld\n", ans + 1);
    return 0;
}