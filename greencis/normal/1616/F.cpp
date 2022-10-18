#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(n, -1));
        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            auto& ed = edges[i];
            cin >> ed.a >> ed.b >> ed.c;
            --ed.a; --ed.b;
            a[ed.a][ed.b] = a[ed.b][ed.a] = i;
            ed.c += (ed.c == -1);
        }
        vector<vector<char>> gauss;
        bool changed = true;
        bool good = true;
        while (good && changed) {
            gauss.clear();
            changed = false;
            for (int i = 0; good && i < n; ++i) {
                for (int j = 0; good && j < i; ++j) {
                    if (a[i][j] == -1) continue;
                    for (int k = 0; k < j; ++k) {
                        if (a[i][k] == -1 || a[j][k] == -1) continue;
                        int cnt[4] = {0, 0, 0, 0};
                        ++cnt[edges[a[i][j]].c];
                        ++cnt[edges[a[i][k]].c];
                        ++cnt[edges[a[j][k]].c];
                        if (cnt[0] == 1) { // determine
                            int color = cnt[1] == 2 ? 1 :
                                        cnt[2] == 2 ? 2 :
                                        cnt[3] == 2 ? 3 :
                                        cnt[1] == 0 ? 1 :
                                        cnt[2] == 0 ? 2 : 3;
                            int index = edges[a[i][j]].c == 0 ? a[i][j] :
                                        edges[a[i][k]].c == 0 ? a[i][k] : a[j][k];
                            edges[index].c = color;
                            changed = true;
                        } else if (cnt[0] == 0) { // check if valid
                            if (cnt[1] != 3 && cnt[2] != 3 && cnt[3] != 3 &&
                                (cnt[1] != 1 || cnt[2] != 1 || cnt[3] != 1)) {
                                good = false;
                                break;
                            }
                        } else if (!changed) { // add equation
                            vector<char> row(m + 1);
                            if (edges[a[i][j]].c == 0) row[a[i][j]] = 1;
                            if (edges[a[i][k]].c == 0) row[a[i][k]] = 1;
                            if (edges[a[j][k]].c == 0) row[a[j][k]] = 1;
                            row[m] = char((3 - cnt[1] - cnt[2] * 2) % 3);
                            gauss.push_back(row);
                        }
                    }
                }
            }
        }
        int rows = (int)gauss.size();
        if (good && rows != 0) {
            vector<bool> empty(m + 1);
            vector<int> columns;
            for (int j = 0; j < m; ++j) {
                bool curEmpty = true;
                for (int i = 0; i < rows; ++i) {
                    if (gauss[i][j]) {
                        curEmpty = false;
                        break;
                    }
                }
                empty[j] = curEmpty;
                if (!curEmpty) columns.push_back(j);
            }
            for (int i = 0; i < rows; ++i) {
                vector<char> newRow;
                for (int j = 0; j <= m; ++j) {
                    if (!empty[j]) {
                        newRow.push_back(gauss[i][j]);
                    }
                }
                newRow.shrink_to_fit();
                swap(gauss[i], newRow);
            }
            int cols = (int)gauss[0].size() - 1;
            int curRow = 0;
            int curCol = 0;
            vector<char> values(cols);
            vector<int> nonEmptyCols;
            while (curRow < rows && curCol < cols) {
                int nonZeroRow = -1;
                for (int i = curRow; i < rows; ++i) {
                    if (gauss[i][curCol] != 0) {
                        nonZeroRow = i;
                        break;
                    }
                }
                if (nonZeroRow == -1) { // curCol is a dependent variable
                    ++curCol;
                    continue;
                }
                swap(gauss[curRow], gauss[nonZeroRow]);
                nonEmptyCols.clear();
                for (int j = cols; j >= curCol; --j) {
                    if (gauss[curRow][j] != 0) {
                        nonEmptyCols.push_back(j);
                        (gauss[curRow][j] *= gauss[curRow][curCol]) %= 3;
                    }
                }
                for (int i = rows - 1; i > curRow; --i) {
                    if (gauss[i][curCol] == 0) continue;
                    for (int col : nonEmptyCols) {
                        gauss[i][col] = (3 + gauss[i][col] - gauss[curRow][col] * gauss[i][curCol]) % 3;
                    }
                }
                ++curCol;
                ++curRow;
            }
            for (int i = curRow; i < rows; ++i) {
                if (gauss[i][cols]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                for (int i = curRow - 1; i >= 0; --i) {
                    int index = -1;
                    int sum = gauss[i][cols];
                    for (int j = 0; j < cols; ++j) {
                        if (gauss[i][j]) {
                            if (index == -1) index = j;
                            else sum -= gauss[i][j] * values[j];
                        }
                    }
                    sum = (sum % 3 + 3) % 3;
                    values[index] = sum;
                }
                for (int i = 0; i < (int)columns.size(); ++i) {
                    edges[columns[i]].c = values[i] == 0 ? 3 : values[i];
                }
            }
        }
        if (good) {
            for (int i = 0; i < m; ++i) {
                if (edges[i].c == 0)
                    edges[i].c = 1;
                cout << edges[i].c << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
}