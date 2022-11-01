#include <bits/stdc++.h>

#define MN 1001000
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll n, m, ans, ways = 1;
int al[5005][5005], z[5005];
vector<int> c[5050];

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 5005; j++)
            al[j][i] += al[j][i-1];

        scanf("%lld", &z[i]);
        al[z[i]][i]++;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        c[x].push_back(y);
    }

    for(int i = 0; i <= n; i++) {
        sort(c[i].begin(), c[i].end());
    }

    for(int l = 0; l <= n; l++) {
        int ok = (l == 0);
        int r = n - l;

        ll mans = 0, mways = 1;

        for(int i = 1; i <= n; i++) {
            vector<int> &v = c[i];
            if(v.empty()) continue;

            if(l && z[l] == i) {
                int ql = al[i][l], qr = al[i][n] - ql;

                if(v.size() > 1 && ((v[0] <= ql && v[1] <= qr) || (v[0] <= qr && v[1] <= ql))) {
                    mans += 2;
                    ll jon = 0;

                    int tmp = (int)v.size()-1;
                    while(v[tmp] > qr) tmp--;

                    for(int j = 0; j < v.size() && v[j] <= ql; j++) {
                        if(v[j] != ql) continue;
                        ok = 1;

                        if(j <= tmp) jon += tmp;
                        else jon += tmp + 1;
                    }

                    mways = mways * jon % MOD;

                } else if(v[0] <= ql || v[0] <= qr) {
                    mans++;

                    ll tmp = 0;
                    for(int x : v) {
                        if(x == ql) { tmp++; ok = 1; }
                        else if(x <= qr) tmp++;
                    }
                    mways = mways * tmp % MOD;
                }
            }

            else {
                int ql = al[i][l], qr = al[i][n] - ql;

                if(v.size() > 1 && ((v[0] <= ql && v[1] <= qr) || (v[0] <= qr && v[1] <= ql))) {
                    mans += 2;
                    ll jon = 0;

                    int tmp = (int)v.size()-1;
                    while(v[tmp] > qr) tmp--;

                    for(int j = 0; j < v.size() && v[j] <= ql; j++) {
                        if(j <= tmp) jon += tmp;
                        else jon += tmp + 1;
                    }

                    mways = mways * jon % MOD;

                } else if(v[0] <= ql || v[0] <= qr) {
                    mans++;

                    ll tmp = 0;
                    for(int x : v) {
                        if(x <= ql) tmp++;
                        if(x <= qr) tmp++;
                    }
                    mways = mways * tmp % MOD;
                }
            }
        }

        if(ok) {
            if(ans == mans) {
                ways += mways;
                if(ways >= MOD) ways -= MOD;
            }
            else if(ans < mans) {
                ans = mans;
                ways = mways;
            }
        }
    }

    if(ans == 0) ways = 1;
    printf("%lld %lld\n", ans, ways);
    return 0;
}