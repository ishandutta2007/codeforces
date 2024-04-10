#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n;
int m;
int c;
int c0;
int st[N];
int t[4 * N];
int shit[4 * N];
vector < pair < int, pair < int, int > > > a;

void build(int x, int l, int r)
{
        shit[x] = 0;

        if(l == r){
                t[x] = c0 - a[l].fi;
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

void upd(int x, int l, int r, int tl, int tr, int y)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                t[x] += y;
                shit[x] += y;
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);

        t[x] = max(t[x * 2], t[x * 2 + 1]) + shit[x];
}

int inf = -1e9;
int get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return inf;
        } else if(tl == l && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return max(get(x * 2, l, m, tl, min(m, tr)),
                   get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr)) + shit[x];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        set < pair < int, int > > S;

        int q;
        scanf("%d", &q);
        while(q--){
                scanf("%d%d%d%d", &n, &m, &c, &c0);
                a.resize(n + 2);
                S.clear();

                for(int i = 0; i < n; i++){
                        scanf("%d%d%d", &a[i].fi, &a[i].se.fi, &a[i].se.se);
                }
                a[n] = {0, {0, 0}};
                a[n + 1] = {m, {0, 0}};
                n += 1;

                sort(a.begin(), a.end());
                build(1, 0, n);
                st[0] = 0;
                for(int i = 1; i <= n; i++){
                        if(a[i].fi == a[i - 1].fi){
                                st[i] = st[i - 1];
                        } else{
                                st[i] = i;
                        }
                }

                long long res = 0;
                for(int i = 1; i <= n && c0 >= 0; i++){
                        int dif = a[i].fi - a[i - 1].fi;
                        c0 -= dif;
                        if(c0 >= 0){
                                S.insert({a[i - 1].se.se, i - 1});
                                continue;
                        }
                        S.insert({a[i - 1].se.se, i - 1});
                        while(!S.empty() && c0 < 0){
                                int x = S.begin()->se;
                                int can = min(- c0, a[x].se.fi);
                                can = min(can, c - get(1, 0, n, st[x], n));
                                if(can == 0){
                                        S.erase(S.begin());
                                        continue;
                                }
                                res += 1ll * can * a[x].se.se;
                                a[x].se.fi -= can;
                                upd(1, 0, n, st[x], n, can);
                                c0 += can;
                        }
                }
                if(c0 < 0){
                        res = -1;
                }
                printf("%lld\n", res);
        }
}