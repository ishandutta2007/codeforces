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

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

bool cor(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void compDFS(int x, int y, const vector< string > &field, vector< vector< int > > &comps, int comp) {
    comps[x][y] = comp;
    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!cor(nx, ny, field.size(), field[0].size())) {
            continue;
        }
        if (field[nx][ny] == '0' && comps[nx][ny] == -1e9) {
            compDFS(nx, ny, field, comps, comp);
        }
    }
}

int markDFS(int x, int y, const vector< string > &field, vector< vector< int > > &comps, 
            vector< vector< bool > > &visited, int comp) {
    visited[x][y] = true;
    bool ok = true;
    int res = 0;
    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!cor(nx, ny, field.size(), field[0].size())) {
            ok = false;
            continue;
        }
        if (field[nx][ny] == '0' && comps[nx][ny] != comp) {
            ok = false;
        }
        if (field[nx][ny] == '1' && comps[nx][ny] != comp) {
            comps[nx][ny] = comp;
            ++res;
        }
        if (!visited[nx][ny] && field[nx][ny] == '0') {
            int nres = markDFS(nx, ny, field, comps, visited, comp);
            if (nres == -1) {
                ok = false;
            } else {
                res += nres;
            }
        }
    }
    if (!ok) {
        return -1;
    } else {
        return res;
    }
}

int onesSize(int x, int y, const vector< string > &field, vector< vector< int > > &comps, int comp) {
    int res = 1;
    comps[x][y] = -comp - 1;
    int neigh = 0;
    bool ok = true;
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!cor(nx, ny, field.size(), field[0].size())) {
            continue;
        }
        if (field[nx][ny] == '0') {
            continue;
        }
        if (comps[nx][ny] == comp || comps[nx][ny] == -comp - 1) {
            ++neigh;
        }
        if (comps[nx][ny] == comp) {
            int nres = onesSize(nx, ny, field, comps, comp);
            if (nres == -1) {
                ok = false;
            } else {
                res += nres;
            }
        }
    }
    if (neigh != 2) {
        ok = false;
    }
    if (!ok) {
        return -1;
    } else {
        return res;
    }
}

int main() {
    int N, M;
    fin >> N >> M;
    vector< string > f(N);
    for (int i = 0; i < N; ++i) {
        fin >> f[i];
    }
    vector< vector< int > > comps(N, vector< int >(M, -1e9));
    int curComp = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (f[i][j] == '0' && comps[i][j] == -1e9) {
                compDFS(i, j, f, comps, curComp++);
            }
        }
    }

    vector< bool > compDone(curComp, false);
    vector< vector< bool > > visited(N, vector< bool > (M, false));
    int res = 0;
    for (int i = 0; i + 1 < N; ++i) {
        for (int j = 0; j + 1 < M; ++j) {
            if (f[i][j] == '1' && f[i + 1][j] == '1' && f[i][j + 1] == '1' && f[i + 1][j + 1] == '1') {
                res = 4;                
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (f[i][j] == '1') {
                continue;
            }
            if (compDone[comps[i][j]]) {
                continue;
            }
            compDone[comps[i][j]] = true;
            int cycleSize = markDFS(i, j, f, comps, visited, comps[i][j]);
            if (cycleSize == -1) {
                continue;
            }
            int oSize = onesSize(i, j - 1, f, comps, comps[i][j]);
            if (oSize != cycleSize) {
                continue;
            }
            res = max(res, oSize);
        }
    }

    fout << res << '\n';

    return 0;
}