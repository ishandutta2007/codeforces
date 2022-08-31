#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef pair<int, int> pii;

char field[1000][1001];
int fn[1000][1000];

int N, M;

vector< vector<pii> > fig;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void repaint(int k) {
    for (size_t i = 0; i < fig[k].size(); ++i) {
        field[fig[k][i].first][fig[k][i].second] = '.';
    }
    bool v[10];
    for (int c = 0; c < 10; ++c) {
        v[c] = false;
    }
    for (size_t i = 0; i < fig[k].size(); ++i) {
        int x = fig[k][i].first, y = fig[k][i].second;
        for (int d = 0; d < 4; ++d) {
            int xx = x + dx[d], yy = y + dy[d];
            if (x < 0 || x >= N || y < 0 || y >= M) {
                continue;
            }
            if (field[xx][yy] >= '0' && field[xx][yy] <= '9') {
                v[field[xx][yy] - '0'] = true;
            }
        }
    }
    int c = 0;
    while (v[c]) {
        ++c;
    }
    for (size_t i = 0; i < fig[k].size(); ++i) {
        int x = fig[k][i].first, y = fig[k][i].second;
        field[x][y] = c + '0';
        fn[x][y] = k;
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%s", field[i]);
    }
    bool ok = true;
    for (int i = 0; ok && i < N; ++i) {
        for (int j = 0; ok && j < M; ++j) {
            if (field[i][j] != '.') {
                continue;
            }
            vector<pii> cfig;
            cfig.pb(mp(i, j));
            bool newFig = true;
            int figN = -1;

            if (j + 1 < M && field[i][j + 1] != '#') {
                if (field[i][j + 1] == '.') {
                    cfig.pb(mp(i, j + 1));
                } else {
                    newFig = false;
                    figN = fn[i][j + 1];
                }
            } else {
                if (i + 1 < N && field[i + 1][j] != '#') {
                    if (field[i + 1][j] == '.') {
                        cfig.pb(mp(i + 1, j));
                    } else {
                        newFig = false;
                        figN = fn[i + 1][j];
                    }
                } else {
                    newFig = false;
                    if (i > 0 && field[i - 1][j] != '#') {
                        figN = fn[i - 1][j];
                    } else {
                        if (j > 0 && field[i][j - 1] != '#') {
                            figN = fn[i][j - 1];
                        } else {
                            ok = false;
                        }
                    }
                }
            }
            if (!ok) {
                break;
            }
            if (newFig) {
                fig.pb(cfig);
                repaint(fig.size() - 1);
            } else {
                fig[figN].pb(mp(i, j));
                repaint(figN);
            }
        }
    }
    if (!ok) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < N; ++i) {
            printf("%s\n", field[i]);
        }
    }

	return 0;
}