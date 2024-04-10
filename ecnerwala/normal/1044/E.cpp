#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
const int MAXM = 30;
int N, M;
int X[MAXN][MAXM];

int total_cost;
vector<vector<int>> answer;
void cycle(vector<pair<int, int>> vec) {
    assert(!vec.empty());
    vector<int> vals;
    for (auto it : vec) {
        assert(0 <= it.first && it.first < N);
        assert(0 <= it.second && it.second < M);
        vals.push_back(X[it.first][it.second]);
    }
    total_cost += int(vals.size());
    answer.push_back(vals);
    int prv = vals.back();
    for (auto it : vec) {
        int cur = X[it.first][it.second];
        X[it.first][it.second] = prv;
        prv = cur;
    }
}

void cycleDown(int i, int j) {
    assert(0 <= i && i+1 < N);
    assert(0 <= j && j+1 < M);
    cycle(vector<pair<int, int>>{{i, j}, {i+1, j}, {i+1, j+1}, {i, j+1}});
}
void cycleRight(int i, int j) {
    assert(0 <= i && i+1 < N);
    assert(0 <= j && j+1 < M);
    cycle(vector<pair<int, int>>{{i, j}, {i, j+1}, {i+1, j+1}, {i+1, j}});
}
void moveRight(int& i, int& j) {
    assert(j+1 < M);
    if (i < N-1) {
        cycleRight(i, j);
    } else {
        cycleDown(i-1, j);
    }
    j++;
}
void moveLeft(int& i, int& j) {
    assert(j-1 >= 0);
    if (i < N-1) {
        cycleDown(i, j-1);
    } else {
        cycleRight(i-1, j-1);
    }
    j--;
}
void moveUp(int& i, int& j) {
    assert(i-1 >= 0);
    if (j < M-1) {
        cycleRight(i-1, j);
    } else {
        cycleDown(i-1, j-1);
    }
    i--;
}
void moveDown(int& i, int& j) {
    assert(i+1 < N);
    if (j < M-1) {
        cycleDown(i, j);
    } else {
        cycleRight(i, j-1);
    }
    i++;
}

void swapBot() {
    cycle(vector<pair<int, int>>{{N-2, M-3}, {N-2, M-2}, {N-2, M-1}, {N-1, M-1}, {N-1, M-2}, {N-1, M-3}});
    cycleDown(N-2, M-3);
    cycleDown(N-2, M-2);
}
void swapRight() {
    cycleRight(N-2, M-2);
    swapBot();
    cycleDown(N-2, M-2);
}

void find(int v, int& i, int& j) {
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (X[i][j] == v) return;
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> X[i][j];
            X[i][j]--;
        }
    }
    for (int di = 0; di < N-2; di++) {
        for (int dj = 0; dj < M; dj++) {
            int v = di * M + dj;
            int si, sj; find(v, si, sj);
            assert(si >= di);
            while (sj > dj) {
                moveLeft(si, sj);
            }
            while (sj < dj) {
                moveRight(si, sj);
            }
            assert(sj == dj);
            assert(si >= di);
            if (dj < M-1) {
                while (si > di) {
                    moveUp(si, sj);
                }
                assert(si == di && sj == dj);
            } else {
                if (si == di) continue;
                assert(si > di);
                if (si == di + 1) {
                    moveDown(si, sj);
                }
                while (si > di + 2) {
                    moveUp(si, sj);
                }
                assert(si == di + 2);
                cycleRight(di, dj-1);
                cycleRight(di, dj-1);
                cycle(vector<pair<int, int>>{{di+2, dj}, {di+1, dj}, {di, dj}, {di, dj-1}, {di+1, dj-1}, {di+2, dj-1}});
                cycle(vector<pair<int, int>>{{di+2, dj}, {di+1, dj}, {di, dj}, {di, dj-1}, {di+1, dj-1}, {di+2, dj-1}});
                assert(X[di][dj] == v);
            }
        }
    }
    for (int dj = 0; dj < M-2; dj++) {
        for (int di = N-2; di < N; di++) {
            int v = di * M + dj;
            int si, sj; find(v, si, sj);
            while (si > di) {
                moveUp(si, sj);
            }
            while (si < di) {
                moveDown(si, sj);
            }
            assert(si == di);
            assert(sj >= dj);
            if (di == N-2) {
                while (sj > dj) {
                    moveLeft(si, sj);
                }
                assert(si == di && sj == dj);
                continue;
            } else {
                if (sj == dj) continue;
                assert(sj > dj);
                if (sj == dj + 1) {
                    moveRight(si, sj);
                }
                while (sj > dj + 2) {
                    moveLeft(si, sj);
                }
                assert(sj == dj + 2);
                cycleRight(di-1, dj);
                cycleRight(di-1, dj);
                cycle(vector<pair<int, int>>{{di, dj+2}, {di, dj+1}, {di, dj}, {di-1, dj}, {di-1, dj+1}, {di-1, dj+2}});
                cycle(vector<pair<int, int>>{{di, dj+2}, {di, dj+1}, {di, dj}, {di-1, dj}, {di-1, dj+1}, {di-1, dj+2}});
                assert(X[di][dj] == v);
            }
        }
    }

    // now we just have the bottom
    int va = (N-2) * M + (M-2);
    while (X[N-2][M-2] != va) cycleRight(N-2, M-2);
    int vd = (N-1) * M + (M-1);
    if (X[N-1][M-2] == vd) {
        swapBot();
    }
    if (X[N-2][M-1] == vd) {
        swapRight();
    }
    assert(X[N-1][M-1] == vd);
    if (X[N-2][M-1] != (N-2) * M + (M-1)) {
        swapBot();
        swapRight();
        swapBot();
    }

    cerr << total_cost << ' ' << "moves" << '\n';
    cout << answer.size() << '\n';
    for (const auto& vec : answer) {
        cout << vec.size();
        for (int v : vec) {
            cout << ' ' << v+1;
        }
        cout << '\n';
    }
}