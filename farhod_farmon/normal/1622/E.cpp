#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 5005;
const int mod = 998244353;

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<vector<char>> a(n, vector<char> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                a[i][j] -= '0';
            }
        }
        long long res = -1e18, mask;
        vector<int> d(m);
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < m; j++) {
                d[j] = 0;
            }
            long long cur = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    cur -= x[j];
                    for (int h = 0; h < m; h++) {
                        d[h] += a[j][h];
                    }
                } else {
                    cur += x[j];
                    for (int h = 0; h < m; h++) {
                        d[h] -= a[j][h];
                    }
                }
            }
            sort(d.begin(), d.end());
            for (int i = 0; i < m; i++) {
                cur += (i + 1) * d[i];
            }
            res = max(res, cur);
            if (res == cur) {
                mask = i;
            }
        }
        vector<pair<int, int>> dd(m, make_pair(0, 0));
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                for (int h = 0; h < m; h++) {
                    dd[h].fi += a[j][h];
                }
            } else {
                for (int h = 0; h < m; h++) {
                    dd[h].fi -= a[j][h];
                }
            }
        }
        vector<int> f(m);
        for (int i = 0; i < m; i++) {
            dd[i].se = i;
        }
        sort(dd.begin(), dd.end());
        for (int i = 0; i < m; i++) {
            f[dd[i].se] = i + 1;
        }
        for (int x : f){
            cout << x << " ";
        }
        cout << '\n';
    }
};