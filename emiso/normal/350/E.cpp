#include <bits/stdc++.h>

using namespace std;

int n, m, k, ispiv[303];
vector<int> piv, notpiv, bolo;
vector<pair<int, int>> edg;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    if(k == n) {
        puts("-1");
        return 0;
    }

    for(int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        piv.push_back(x);
        ispiv[x] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(!ispiv[i]) notpiv.push_back(i);
    }

    int s, t, mid;

    mid = notpiv.back();
    notpiv.pop_back();

    s = piv.back();
    piv.pop_back();

    t = piv.back();
    piv.pop_back();

    edg.emplace_back(s, mid);
    edg.emplace_back(mid, t);

    while(!notpiv.empty()) {
        int u = notpiv.back();
        notpiv.pop_back();
        bolo.push_back(u);
        edg.emplace_back(u, t);
    }

    while(!piv.empty()) {
        int u = piv.back();
        piv.pop_back();
        bolo.push_back(u);
        edg.emplace_back(u, t);
    }

    while(!bolo.empty()) {
        int u = bolo.back();
        bolo.pop_back();

        for(int v : bolo)
            edg.emplace_back(u, v);

        edg.emplace_back(u, mid);
        if(!ispiv[u]) edg.emplace_back(s, u);
    }

    if(edg.size() < m) {
        puts("-1");
        return 0;
    }

    edg.resize(m);
    for(auto e : edg) {
        printf("%d %d\n", e.first, e.second);
    }
    return 0;
}