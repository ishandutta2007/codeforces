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

const int N = 2e5 + 7;

vector <int> g[N];
int pr[N];
bool used[N];
vector <int> best[N];
int d[N];

void fsd(int u, int p = -1) {
    d[u] = 0;
    for (auto v : g[u]) {
        if (v != p) {
            fsd(v, u);
            d[u] = max(d[u], d[v] + 1);
        }
    }
}

void jhfs(int u, int p = -1, int bst = 0) {
    int a = -1, b = -1;
    for (auto v : g[u]) {
        if (v != p) {
            if (a == -1 || d[a] < d[v]) {
                b = a;
                a = v;
            }
            else if (b == -1 || d[b] < d[v]) {
                b = v;
            }
        }
    }
    for (int i = 0; i < g[u].size(); ++i) {
        if (g[u][i] != p) {
            best[u][i] = d[g[u][i]];
            if (g[u][i] == a) {
                if (b == -1) {
                    jhfs(g[u][i], u, bst + 1);
                }
                else {
                    jhfs(g[u][i], u, max(bst + 1, d[b] + 1));
                }
            }
            else {
                jhfs(g[u][i], u, max(bst + 1, d[a] + 1));
            }
        }
        else {
            best[u][i] = bst;
        }
    }

}

int ans = -1;
int ansa = -1, ansb = -1, ansc = -1, ansd = -1;
int anss = -1;
int wha = -1, whb = -1;

int cur;
int a, b, w;
int who;

void dfs_centroid(int u, int d, int p) {
    int cnt = 0;
    for (auto v : g[u]) {
        if (v != p && !used[v]) {
            ++cnt;
            dfs_centroid(v, d + 1, u);
        }
    }
    if (cnt >= 2) {
        int mx1 = -1, mx2 = -1;
        int ta = -1, tb = -1;
        for (int i = 0; i < g[u].size(); ++i) {
            if (g[u][i] != p) {
                if (best[u][i] > mx1) {
                    tb = ta;
                    ta = g[u][i];
                    mx2 = mx1;
                    mx1 = best[u][i];
                }
                else if (best[u][i] > mx2) {
                    tb = g[u][i];
                    mx2 = best[u][i];
                }
            }
        }
        int sum = mx1 + mx2;

        if (d > cur || (d == cur && sum > w)) {
            cur = d;
            who = u;
            w = sum;
            a = ta;
            b = tb;
        }
    }
}

int dfs(int u, int size, int &c, int p = -1) {
    int sum = 1;
    for (auto v : g[u]) {
        if (v != p && !used[v]) {
            sum += dfs(v, size, c, u);
        }
    }
    if (c == -1 && (2 * sum >= size || p == -1)) {
        c = u;
    }
    return sum;
}

void build(int u, int size, int last = -1) {
    int c = -1;
    dfs(u, size, c);
    pr[c] = last;
    used[c] = 1;

    int f = -1, s = -1, t = -1;
    for (int i = 0; i < g[c].size(); ++i) {
        int v = g[c][i];
        if (!used[v]) {
            if (f == -1 || best[c][i] > f) {
                t = s;
                s = f;
                f = i;
            }
            else if (s == -1 || best[c][i] > s) {
                t = s;
                s = i;
            }
            else if (t == -1 || best[c][i] > t) {
                t = i;
            }
        }
    }
    int mx1 = -1, mx1a = -1, mx1b = -1, mx1s = -1, mx2 = -1, mx2a = -1, mx2b = -1, mx2s = -1, mx1wh = -1, mx2wh = -1;
    int idx = 0;
    for (auto v : g[c]) {
        if (!used[v]) {
            cur = -1, a = -1, b = -1, w = -1, who = -1;
            dfs_centroid(v, 1, c);
            if (f != -1 && s != -1 && t != -1) {
                int wa = -1, wb = -1;
                int summa = 0;
                if (f == idx) {
                    summa += best[c][s];
                    summa += best[c][t];
                    wa = g[c][s];
                    wb = g[c][t];
                }
                else if (s == idx) {
                    summa += best[c][f];
                    summa += best[c][t];
                    wa = g[c][f];
                    wb = g[c][t];
                }
                else {
                    summa += best[c][f];
                    summa += best[c][s];
                    wa = g[c][f];
                    wb = g[c][s];
                }
                if (cur > ans || (cur == ans && summa + w > anss)) {
                    ans = cur;
                    anss = summa + w;
                    ansa = a;
                    ansb = b;
                    ansc = wa;
                    ansd = wb;
                    wha = who;
                    whb = c;
                }
            }
            if (mx1 < cur || (mx1 == cur && mx1s < w)) {
                mx2 = mx1;
                mx2s = mx1s;
                mx2a = mx1a;
                mx2b = mx1b;
                mx2wh = mx1wh;
                mx1 = cur;
                mx1s = w;
                mx1a = a;
                mx1b = b;
                mx1wh = who;
            }
            else if (mx2 < cur || (mx2 == cur && mx2s < w)) {
                mx2 = cur;
                mx2s = w;
                mx2a = a;
                mx2b = b;
                mx2wh = who;

            }
        }
        ++idx;
    }
    if (mx1 != -1 && mx2 != -1) {
        if (mx1 + mx2 > ans || (mx1 + mx2 == ans && mx1s + mx2s > anss)) {
            ans = mx1 + mx2;
            anss = mx1s + mx2s;
            ansa = mx1a;
            ansb = mx1b;
            ansc = mx2a;
            ansd = mx2b;
            wha = mx1wh;
            whb = mx2wh;
        }
    }

    for (auto v : g[c]) {
        if (!used[v]) {
            build(v, (size + 1) / 2, c);
        }
    }
}

pair <int, int> find(int u, int p) {
    pair <int, int> cur = {u, 0};
    for (auto v : g[u]) {
        if (v != p) {
            auto pr = find(v, u);
            if (pr.second + 1 > cur.second) {
                cur = pr;
                ++cur.second;
            }
        }
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        best[i].resize(g[i].size());
    }
    fsd(0);
    jhfs(0);

    build(0, n);
    //cout << ansa + 1 << ' ' << ansb + 1 << ' ' << ansc + 1 << ' ' << ansd + 1 << ' ' << wha + 1 << ' ' << whb + 1 << '\n';
    //return 0;
    ansa = find(ansa, wha).first + 1;
    ansb = find(ansb, wha).first + 1;
    ansc = find(ansc, whb).first + 1;
    ansd = find(ansd, whb).first + 1;
    cout << ansa << ' ' << ansc << '\n' << ansb << ' ' << ansd << '\n';
}