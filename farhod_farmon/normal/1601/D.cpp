#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n;
int d;
pair<int, int > a[N];

int inf = 1e9;
int t[4 * N];
int lz[4 * N];

void upd(int x, int l, int r, int tl, int tr, int g)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                t[x] += g;
                lz[x] += g;
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), g);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
        t[x] = max(t[x * 2], t[x * 2 + 1]) + lz[x];
}

void upd(int x, int l, int r, int g, int y)
{
        if(l == r){
                t[x] = y;
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g, y);
        } else{
                upd(x * 2 + 1, m + 1, r, g, y);
        }
        t[x] = max(t[x * 2], t[x * 2 + 1]) + lz[x];
}

int get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return -inf;
        } else if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr)) + lz[x];
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> d;
        for(int i = 1; i <= n; i++){
                cin >> a[i].se >> a[i].fi;
                if(a[i].se < d){
                        i--;
                        n--;
                        continue;
                }
                a[i].se = - a[i].se;
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i < 4 * N; i++){
                t[i] = - inf;
        }
        int res = 0;
        set<pair<int, int>> s;
        upd(1, 0, n, 0, 0);
        for(int i = 1; i <= n; i++){
                a[i].se = - a[i].se;
                int l = 0, r = i - 1;
                while(l < r){
                        int m = (l + r) / 2;
                        if(a[i].se >= a[m + 1].fi){
                                l = m + 1;
                        } else{
                                r = m;
                        }
                }
                while(!s.empty() && s.begin()->fi < a[i].fi){
                        upd(1, 0, n, 0, s.begin()->se - 1, -1);
                        s.erase(s.begin());
                }

                int cur = get(1, 0, n, 0, l) + 1;
                res = max(res, cur);
                upd(1, 0, n, i, cur);
                upd(1, 0, n, 0, i - 1, 1);
                s.insert({a[i].se, i});
        }

        cout << res << "\n";
}