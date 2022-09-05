#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;
int n, d[maxn], s[maxn];
queue<int> Q;
vector<pair<int, int>> E;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &d[i], &s[i]);
        if (d[i] == 1) Q.push(i);
    }
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        if (!d[v]) continue;
        E.emplace_back(v, s[v]);
        d[s[v]]--, s[s[v]] ^= v;
        if (d[s[v]] == 1) Q.push(s[v]);
    }
    printf("%d\n", E.size());
    for (auto p : E) printf("%d %d\n", p.first, p.second);
    return 0;
}