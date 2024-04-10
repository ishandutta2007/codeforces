#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    vector <int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&] (int i, int j) {
        return d[i] > d[j];
    });
    vector <int> par(2 * n, -1);
    for (int i = 1; i < n; ++i) {
        par[2 * p[i]] = 2 * p[i - 1];
    }
    int curDist = n, curV = 2 * p[n - 1];
    for (int i = 0; i < n; ++i) {
        --curDist;
         int cur = 2 * p[i] + 1;
        if (i + d[p[i]] - 1 < n) {
            int nd = 2 * p[i + d[p[i]] - 1];
            par[cur] = nd;
            curV = cur;
            curDist = d[p[i]];
            continue;
        }
        while (curDist + 1 > d[p[i]]) {
            --curDist;
            curV = par[curV];
        }
        par[cur] = curV;
        curV = cur;
        ++curDist;
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (par[i] != -1) {
            cout << par[i] + 1 << ' ' << i + 1 << '\n';
        }
    }
}