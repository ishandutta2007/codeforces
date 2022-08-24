#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

struct TEdge {
    int to;
    long long l;

    TEdge(int _to, long long _l)
        : to(_to)
        , l(_l)
    {
    }
};

struct TEntry {
    long double a;
    long long L;
    long long S;

    TEntry(long double _a, long long _L, long long _S)
        : a(_a)
        , L(_L)
        , S(_S)
    {
    }

    bool operator <(TEntry &r) {
        return L * r.S < r.L * S;
    }
};

long double btime(int x, vector< bool > &visited, vector< vector< TEdge > > &edges,
             vector< long long > &L, vector< long long > &S) {
    visited[x] = true;
    S[x] = 1;
    vector< TEntry > sons;
    for (size_t i = 0; i < edges[x].size(); ++i) {
        if (!visited[edges[x][i].to]) {
            long double t = btime(edges[x][i].to, visited, edges, L, S);
            sons.push_back(TEntry(edges[x][i].l + t, L[edges[x][i].to] + 2 * edges[x][i].l, S[edges[x][i].to]));
            S[x] += S[edges[x][i].to];
            L[x] += L[edges[x][i].to] + 2 * edges[x][i].l;
        }
    }
    sort(sons.begin(), sons.end());
    long double ans = 0.0;
    long long sumL = 0;
    for (size_t i = 0; i < sons.size(); ++i) {
        ans += 1.0 * sons[i].S * (sumL + sons[i].a) / S[x];
        sumL += sons[i].L;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector< vector< TEdge > > edges(n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        --x; --y;
        edges[x].push_back(TEdge(y, w));
        edges[y].push_back(TEdge(x, w));
    }
    vector< long long > L(n), S(n);
    vector< bool > visited(n, false);
    printf("%.10Lf\n", btime(0, visited, edges, L, S) * n / (n - 1));

    return 0;
}