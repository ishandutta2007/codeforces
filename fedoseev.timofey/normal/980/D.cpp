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

using namespace std;

typedef long long ll;

vector <int> p;

int get(int u) {
    if (u == p[u]) return u;
    else return p[u] = get(p[u]);
}

map <int, int> factorize(int n) {
    map <int, int> res;
    for (int d = 2; d * d <= n; ++d) {
        while (n % d == 0) {
            n /= d;
            ++res[d];
        }
    }
    if (n != 1) ++res[n];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) p[i] = i;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <map <int, int>> factor(n);
    vector <vector <int>> f(n);
    for (int i = 0; i < n; ++i) {
        factor[i] = factorize(abs(a[i]));
        for (auto p : factor[i]) {
            if (p.second % 2 == 1) {
                f[i].push_back(p.first);
            }
        }
        factor[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) continue;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] == 0) continue;
            if ((ll)a[i] * a[j] > 0) {
                auto &f1 = f[i];
                auto &f2 = f[j];
                if (f1 == f2) {
                    p[get(i)] = get(j);
                }
            }
        }
    }
    vector <int> ans(n + 1);
    for (int l = 0; l < n; ++l) {
        int cnt = 1;
        vector <int> gr(n);
        bool fl = 0;
        if (a[l] != 0) gr[get(l)] = 1;
        else {
            fl = 1;
        }
        ++ans[cnt];
        for (int r = l + 1; r < n; ++r) {
            if (a[r] && gr[get(r)] == 0) {
                gr[get(r)] = 1;
                if (fl) {
                    fl = 0;
                }
                else {
                    ++cnt;
                }
            }
            ++ans[cnt];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}