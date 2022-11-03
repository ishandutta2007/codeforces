#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 6;
const int A = 21;
const int LOGN = 20;
const int B = 300;

/*

*/

pii a[N];
int r[N], ri[N];
int ind[N];
int dp[N], nxt[N], nr[N];

int max2[N];
int st[LOGN][N];

int get(int lf, int rg) {
    int len = max2[rg - lf];

    return max(st[len][lf], st[len][rg - (1 << len)]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<pii> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
        s.insert({a[i].f, i});
        ind[i] = i / B;
    }

    max2[1] = 0;
    for(int i = 2; i < N; i++) {
        max2[i] = max2[i / 2] + 1;
    }

    for(int i = n - 1; i >= 0; i--) {
//        cout << "for " << i << endl;

        r[i] = a[i].f + a[i].s;
        auto it = s.upper_bound({r[i], INF});
        it--;

//        cout << it->s << ' ' << get(i + 1, it->s + 1) << endl;

        if(it->s != i) {
            r[i] = max(r[i], get(i + 1, it->s + 1));
        }

//        cout << it->s << ' ' << get(i + 1, it->s + 1) << ' ' << r[i] << endl;

        it = s.upper_bound({r[i], INF});
        it--;
        int j = it->s;

        ri[i] = j;

        if(ind[i] != ind[n - 1]) {

            if(j == i) {
                if(ind[i + 1] != ind[i]) {
                    dp[i] = a[i + 1].f - r[i];
                    nxt[i] = i + 1;
                    nr[i] = r[i + 1];
                } else {
                    dp[i] = a[i + 1].f - r[i] + dp[i + 1];
                    nxt[i] = nxt[i + 1];
                    nr[i] = nr[i + 1];
                }
            } else {
                if(ind[j] > ind[i]) {
                    dp[i] = 0;
                    nxt[i] = j;
                    nr[i] = r[i];
                } else if(ind[j + 1] > ind[i]) {
                    dp[i] = a[j + 1].f - r[i];
                    nxt[i] = j + 1;
                    nr[i] = r[i + 1];
                } else {
                    dp[i] = a[j + 1].f - r[i] + dp[j + 1];
                    nxt[i] = nxt[j + 1];
                    nr[i] = nr[j + 1];
                }
            }
        }

        st[0][i] = r[i];
        for(int j = 1; j < LOGN; j++)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    }

//    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << r[i] << ' '<< dp[i] << ' '<< nxt[i] << endl;
//    }

    int q;
    cin >> q;

    while(q--) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        int res = 0;
        int rg = r[x];
        while(x < y) {
//            cout << x << ' ' << rg << ' ' << res << endl;
            if(ind[x] == ind[y]) {
                rg = max(rg, r[x]);
                while(x < y) {
                    res += max(0, a[x + 1].f - rg);
                    x++;
                    rg = max(rg, r[x]);
                }
            } else {
                if(rg > r[x]) {
                    res += a[x + 1].f - rg;
                    rg = r[x + 1];
                    x++;
                } else {
                    res += dp[x];
                    rg = nr[x];
                    x = nxt[x];
//                    rg = r[x];
                }

            }
        }

        cout << res << endl;
    }
}