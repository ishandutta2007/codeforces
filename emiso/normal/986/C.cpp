#include <bits/stdc++.h>
#define MN 5000050

using namespace std;

int n, m, a[MN], ans, ok[MN], usd[MN];
vector<int> cnt(MN);

int parent[MN], sz[MN];

int find(int node) {
    if(node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}

bool join(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return false;

    if(sz[a] > sz[b]) {
        parent[b] = a;
        sz[a] += sz[b];
    } else {
        parent[a] = b;
        sz[b] += sz[a];
    }
    return true;
}

void connect(int mask) {
    if(ok[mask] || !cnt[mask]) return;

    for(int i = 0; i < n; i++) {
        if((1 << i) & mask) {
            int v = mask - (1 << i);
            if(cnt[v]) {
                join(mask, v);
                connect(v);
            }
        }
    }
    ok[mask] = 1;
}

vector<int> FST(vector<int> a, bool inverse = false) {
    for (int b = 0; b < n; b++)
        for (int i = 0; i < (1<<n); i++)
            if ((i & (1 << b)) == 0)
                a[i + (1 << b)] += a[i] * (inverse ? -1 : 1);
    return a;
}

int main() {
    for(int i = 0; i < MN; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]] = 1;
    }

    cnt = FST(cnt);

    for(int i = 0; i < m; i++) {
        int inv = (~a[i]) & ((1 << n) - 1);
        if(cnt[inv]) {
            join(a[i], inv);
            connect(inv);
        }
    }

    for(int i = 0; i < m; i++) {
        if(!usd[find(a[i])]++) ans++;
    }

    printf("%d\n", ans);
    return 0;
}

/*
3 7
7 1 4 0 6 2 5
*/