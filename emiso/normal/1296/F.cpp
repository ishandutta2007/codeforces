#include <bits/stdc++.h>

using namespace std;

int n, m, maxi[5050], h[5050], papai[5050], l[5050], r[5050], co[5050], u[5050], v[5050];
vector<int> adj[5050];

void dfs(int no, int pai = -1) {
    for(int v : adj[no])
        if(pai != v) {
            papai[v] = no;
            h[v] = h[no] + 1;
            dfs(v, no);
        }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        u[i] = a;
        v[i] = b;
    }

    for(int i = 1; i <= n; i++)
        maxi[i] = 1;

    dfs(1);

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        l[i] = a, r[i] = b, co[i] = c;

        if(h[a] < h[b]) swap(a, b);
        while(h[a] > h[b]) {
            maxi[a] = max(maxi[a], c);
            a = papai[a];
        }

        while(a != b) {
            maxi[a] = max(maxi[a], c);
            maxi[b] = max(maxi[b], c);
            a = papai[a];
            b = papai[b];
        }
    }


    for(int i = 0; i < m; i++) {
        int a, b, c, mini = INT_MAX;
        a = l[i], b = r[i], c = co[i];

        if(h[a] < h[b]) swap(a, b);
        while(h[a] > h[b]) {
            mini = min(mini, maxi[a]);
            a = papai[a];
        }

        while(a != b) {
            mini = min(mini, maxi[a]);
            mini = min(mini, maxi[b]);
            a = papai[a];
            b = papai[b];
        }

        if(mini != c) {
            puts("-1");
            return 0;
        }
    }

    for(int i = 1; i < n; i++) {
        int a = u[i], b = v[i];
        if(h[a] < h[b]) printf("%d ", maxi[b]);
        else printf("%d ", maxi[a]);
    }
    return 0;
}