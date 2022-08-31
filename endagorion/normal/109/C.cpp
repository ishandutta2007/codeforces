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

bool happy(int x) {
    if (x == 0) {
        return true;
    }
    if (x % 10 != 4 && x % 10 != 7) {
        return false;
    }
    return happy(x / 10);
}

struct TEdge {
    int to;
    bool hap, ex;

    TEdge(int _to, bool _hap) 
        : to(_to)
        , hap(_hap)
        , ex(true)
    {
    }
};

void dfs_d(int x, int p, vector< vector< TEdge > > &edges, vector< int > &down, vector< int > &s_size) {
    s_size[x] = 1;
    for (size_t i = 0; i < edges[x].size(); ++i) {
        if (edges[x][i].to == p) {
            edges[x][i].ex = false;
            continue;
        }
        dfs_d(edges[x][i].to, x, edges, down, s_size);
        s_size[x] += s_size[edges[x][i].to];
        if (edges[x][i].hap) {
            down[x] += s_size[edges[x][i].to];
        } else {
            down[x] += down[edges[x][i].to];
        }
    }
}

void dfs_u(int x, vector< vector< TEdge > > &edges, vector< int > &down, 
           vector< int > & up, vector< int > &s_size) {
    int sum = 0;
    for (size_t i = 0; i < edges[x].size(); ++i) {
        sum += down[edges[x][i].to];   
    }
    for (size_t i = 0; i < edges[x].size(); ++i) {
        if (!edges[x][i].ex) {
            continue;
        }
        int y = edges[x][i].to;
        if (edges[x][i].hap) {
            up[y] = edges.size() - s_size[y];
        } else {
            up[y] = up[x] + down[x] - down[y];
        }

        dfs_u(y, edges, down, up, s_size);
    }
}

int main() {
    int n;
    cin >> n;
    vector< vector< TEdge > > edges(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        edges[x].push_back(TEdge(y, happy(w)));
        edges[y].push_back(TEdge(x, happy(w)));
    }
    
    vector< int > down(n, 0), up(n, 0), s_size(n, 0);
    dfs_d(0, -1, edges, down, s_size);
    dfs_u(0, edges, down, up, s_size);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long s = up[i] + down[i];
        ans += s * (s - 1);
    }

    cout << ans << '\n';
    return 0;
}