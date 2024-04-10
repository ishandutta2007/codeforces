#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 10007;

vector <int> g[N];
int usedL[N];
int usedR[N];
int matchL[N];
int matchR[N];

int timer = 0;

bool kuhn(int u) {
    if (usedL[u] == timer) return false;
    usedL[u] = timer;
    for (auto v : g[u]) {
        if (matchR[v] == -1) {
            matchR[v] = u;
            return true;
        }
    }
    for (auto v : g[u]) {
        if (kuhn(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

void dfs(int u) {
    usedL[u] = 1;
    for (auto v : g[u]) {
        if (v != matchL[u] && !usedR[v]) {
            usedR[v] = 1;
            if (matchR[v] != -1 && !usedL[matchR[v]]) {
                dfs(matchR[v]);
            }
        }
    }
}

struct segment {
    int x1, y1, x2, y2;
    segment(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> X, Y;
    vector <int> px(n), py(n);
    int fir = -1;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (i == 0) fir = x;
        X.push_back(x);
        Y.push_back(y);
        px[i] = x;
        py[i] = y;
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());

    for (int i = 0; i < n; ++i) {
        px[i] = lower_bound(X.begin(), X.end(), px[i]) - X.begin();
        py[i] = lower_bound(Y.begin(), Y.end(), py[i]) - Y.begin();
    }

    vector <vector <int>> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        xs[px[i]].push_back(py[i]);
        ys[py[i]].push_back(px[i]);
    }
    for (int i = 0; i < n; ++i) {
        sort(xs[i].begin(), xs[i].end());
        sort(ys[i].begin(), ys[i].end());
    }

    for (int i = 0; i < N; ++i) {
        matchL[i] = matchR[i] = -1;
    }

    vector <pair <int, int>> ptx, pty;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < xs[i].size(); ++j) {
            ptx.emplace_back(i, j);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < ys[i].size(); ++j) {
            pty.emplace_back(i, j);
        }
    }

    sort(ptx.begin(), ptx.end());
    sort(pty.begin(), pty.end());

    for (int i = 0; i < ptx.size(); ++i) {
        for (int j = 0; j < pty.size(); ++j) {
            int x = ptx[i].first;
            int y = pty[j].first;
            if (ys[pty[j].first][pty[j].second] < x && x < ys[pty[j].first][pty[j].second + 1]) {
                if (xs[ptx[i].first][ptx[i].second] < y && y < xs[ptx[i].first][ptx[i].second + 1]) {
                    g[i].push_back(j);
                }
            }
        }
    }
    int sz = ptx.size();
    int mem = X.size() + Y.size();

    for (int i = 0; i < sz; ++i) {
        ++timer;
        kuhn(i);
    }
    for (int i = 0; i < pty.size(); ++i) {
        if (matchR[i] != -1) {
            matchL[matchR[i]] = i;
        }
    }
    for (int i = 0; i < sz; ++i) {
        usedL[i] = usedR[i] = 0;
    }
    for (int i = 0; i < sz; ++i) {
        if (matchL[i] == -1) dfs(i);
    }
    vector <vector <int>> hx(n);
    vector <vector <int>> hy(n);
    for (int i = 0; i < n; ++i) {
        hx[i].resize(xs[i].size());
        hy[i].resize(ys[i].size());
    }
    for (int i = 0; i < sz; ++i) {
        if (usedL[i]) {
            hx[ptx[i].first][ptx[i].second] = 1;
        }
    }
    for (int i = 0; i < pty.size(); ++i) {
        if (!usedR[i]) {
            hy[pty[i].first][pty[i].second] = 1;
        }
    }
    vector <segment> vert, horiz;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < xs[i].size(); ++j) {
            if (!hx[i][j]) {
                if (j == 0 || !hx[i][j - 1]) {
                    vert.emplace_back(i, xs[i][j], i, xs[i][j]);
                }
                continue;
            }
            int k = j;
            while (k < xs[i].size() && hx[i][k]) ++k;
            vert.emplace_back(i, xs[i][j], i, xs[i][k]);
            j = k - 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < ys[i].size(); ++j) {
            if (!hy[i][j]) {
                if (j == 0 || !hy[i][j - 1]) {
                    horiz.emplace_back(ys[i][j], i, ys[i][j], i);
                }
                continue;
            }
            int k = j;
            while (k < ys[i].size() && hy[i][k]) ++k;
            horiz.emplace_back(ys[i][j], i, ys[i][k], i);
            j = k - 1;
        }
    }
    cout << horiz.size() << '\n';
    for (auto &s : horiz) {
        cout << X[s.x1] << ' ' << Y[s.y1] << ' ' << X[s.x2] << ' ' << Y[s.y2] << '\n';
    }
    cout << vert.size() << '\n';
    for (auto &s : vert) {
        cout << X[s.x1] << ' ' << Y[s.y1] << ' ' << X[s.x2] << ' ' << Y[s.y2] << '\n';
    }

}