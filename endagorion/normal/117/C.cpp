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

bool dfs(int x, int n, vector< vector< bool > > &matrix,
         vector< int > &visited, vector< int > &path) {
    visited[x] = 1;
    path.push_back(x);
    for (int i = 0; i < n; ++i) {
        if (matrix[x][i]) {
            if (visited[i] == 1) {
                path.push_back(i);
                return true;
            }
            if (visited[i] == 0) {
                if (dfs(i, n, matrix, visited, path)) {
                    return true;
                }
            }
        }
    }
    path.pop_back();
    visited[x] = 2;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector< string > edges(n);
    for (int i = 0; i < n; ++i) {
        cin >> edges[i];
    }
    vector< vector< bool > > matrix(n, vector< bool > (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = edges[i][j] == '1';
        }
    }
    vector< int > path;
    vector< int > visited(n, 0);
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, n, matrix, visited, path)) {
                ok = true;
                break;
            }
        }
    }

    if (!ok) {
        cout << -1 << '\n';
    } else {
        int i = path.size() - 3;
        int j = path.size() - 2;
        int k = path.size() - 1;
        while (true) {
            if (matrix[path[k]][path[i]]) {
                cout << path[i] + 1 << ' ' << path[j] + 1 << ' ' << path[k] + 1 << '\n';
                return 0;
            }
            --i; --j;
        }
    }

    return 0;
}