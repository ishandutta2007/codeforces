#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> szs;
set<pair<int, int>> edges;
set<int> unvisited;

int dfs(int no) {
    unvisited.erase(no);
    int ret = 1;

    for(auto L = unvisited.begin(); L != unvisited.end();) {
        int val = *L;
        if(!edges.count({no, val})) ret += dfs(val);
        L = unvisited.upper_bound(val);
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges.insert({a, b});
        edges.insert({b, a});
    }

    for(int i = 1; i <= n; i++)
        unvisited.insert(i);

    for(int i = 1; i <= n; i++)
        if(unvisited.count(i))
            szs.push_back(dfs(i));

    sort(szs.begin(), szs.end());
    printf("%d\n", szs.size());
    for(int x : szs) printf("%d ", x);
    puts("");

    return 0;
}