#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

#ifndef ONLINE_JUDGE

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);
FILE *file_in = fopen("input.txt", "rt");
FILE *file_out = fopen("output.txt", "wt");

#else

#define fin cin
#define fout cout
#define file_in stdin
#define file_out stdout

#endif

struct TEdge {
    int to, num;

    TEdge(int _to = 0, int _num = 0)
        : to(_to)
        , num(_num) {
    }

    bool operator<(const TEdge &edge) const {
        return to < edge.to;
    }
};

int exists(int x, vector< vector< TEdge > > &edges, vector< bool > &visited) {
    int res = 0;
    for (size_t i = 0; i < edges[x].size(); ++i) {
        if (visited[edges[x][i].num]) {
            continue;
        }
        visited[edges[x][i].num] = true;
        res += exists(edges[x][i].to, edges, visited) + 1;
    }
    return res;
}

bool dfs_next(int x, vector< vector< TEdge > > &edges, vector< bool > &visited,
              int viscount, int total, vector< int > &path, vector< int > &ans, bool eq) {
    if (viscount == total) {
        return !eq;
    }
    ans[viscount] = x;
    for (size_t i = 0; i < edges[x].size(); ++i) {
        if (visited[edges[x][i].num]) {
            continue;
        }
        int y = edges[x][i].to;
        if (eq && y < path[viscount + 1]) {
            continue;
        }
        bool neq = eq && (y == path[viscount + 1]);
        bool poss;
        if (!neq) {
            vector< bool > viscopy(visited);
            viscopy[edges[x][i].num] = true;
            poss = viscount + 1 + exists(y, edges, viscopy) == total;
        }
        if (neq || poss) {
            visited[edges[x][i].num] = true;
            bool result = dfs_next(y, edges, visited, viscount + 1,
                total, path, ans, neq);
            if (result) {
                return true;
            }
            if (eq) {
                visited[edges[x][i].num] = false;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    fin >> n >> m;
    vector< vector< TEdge > > edges(n);
    int last;
    fin >> last;
    --last;
    vector< int > path(m + 1);
    for (int i = 0; i < m; ++i) {
        path[i] = last;
        int next;
        fin >> next;
        --next;
        edges[last].push_back(TEdge(next, i));
        edges[next].push_back(TEdge(last, i));
        last = next;
    }
    path[m] = last;
    for (int i = 0; i < n; ++i) {
        sort(edges[i].begin(), edges[i].end());
    }
    vector< bool > visited(m);
    vector< int > ans(m);
    if (dfs_next(last, edges, visited, 0, m, path, ans, true)) {
        for (size_t i = 0; i < ans.size(); ++i) {
            fout << ans[i] + 1 << ' ';
        }
        fout << last + 1 << '\n';
    } else {
        fout << "No solution\n";
    }

    return 0;
}