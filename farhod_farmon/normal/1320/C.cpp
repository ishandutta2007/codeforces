#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int m;
int k;
long long t[4 * N];
long long lz[4 * N];
pair < int, int > a[N], b[N];

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = - b[l].se;
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

void upd(int x, int l, int r, int tl, int tr, long long y)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                t[x] += y;
                lz[x] += y;
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
        t[x] = max(t[x * 2], t[x * 2 + 1]) + lz[x];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi >> a[i].se;
        }
        for(int i = 1; i <= m; i++){
                cin >> b[i].fi >> b[i].se;
        }
        vector < pair < int, pair < int, int > > > v;
        for(int i = 1, x, y, z; i <= k; i++){
                cin >> x >> y >> z;
                v.push_back({x, {y, z}});
        }
        sort(v.begin(), v.end());
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        build(1, 1, m);

        long long res = -1e18;
        for(int i = 1, j = 0; i <= n; i++){
                while(j < v.size() && v[j].fi < a[i].fi){
                        int l = 1, r = m + 1;
                        while(l < r){
                                int m = (l + r) / 2;
                                if(v[j].se.fi < b[m].fi){
                                        r = m;
                                } else{
                                        l = m + 1;
                                }
                        }
                        upd(1, 1, m, l, m, v[j].se.se);
                        j += 1;
                }
                res = max(res, t[1] - a[i].se);
        }
        cout << res << "\n";
}