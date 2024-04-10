#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500010;

using namespace std;

int n;
int l[N];
int cost[N];
vector < int > L;
vector < pair < int, int > > R;
pair < long long, int > t[4 * N];
long long shit[4 * N];

void open(int x, int l, int r, int g)
{
        if(l == r){
                t[x] = {L[l], L[l]};
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                open(x * 2, l, m, g);
        } else{
                open(x * 2 + 1, m + 1, r, g);
        }

        t[x] = max(t[x * 2], t[x * 2 + 1]);
        t[x].fi += shit[x];
}

void upd(int x, int l, int r, int tl, int tr, int y)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                t[x].fi += y;
                shit[x] += y;
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);

        t[x] = max(t[x * 2], t[x * 2 + 1]);
        t[x].fi += shit[x];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1, x, y, l, r; i <= n; i++){
                cin >> x >> y >> cost[i];

                l = min(x, y);
                r = max(x, y);
                ::l[i] = l;

                L.push_back(l);
                R.push_back({r, i});
        }
        sort(L.begin(), L.end());
        sort(R.begin(), R.end(), [&](pair < int ,int > x, pair < int, int > y){
                if(x.fi < y.fi){
                        return true;
                } else if(x.fi > y.fi){
                        return false;
                }
                return l[x.se] < l[y.se];
        });
        vector < int > nv;
        for(int x: L){
                if(nv.empty() || nv.back() != x){
                        nv.push_back(x);
                }
        }
        L = nv;

        long long best = 0;
        pair < int, int > res = {(int)2e9, (int)2e9};
        for(int i = 0; i < 4 * N; i++){
                t[i] = {-1e18, -1e18};
        }
        int h = 0;

        for(int i = 0; i < R.size(); i++){
                auto x = R[i];
                while(h < L.size() && L[h] <= x.fi){
                        open(1, 0, L.size() - 1, h);
                        h += 1;
                }

                int in = lower_bound(L.begin(), L.end(), l[x.se]) - L.begin();
                upd(1, 0, L.size() - 1, 0, in, cost[x.se]);
                if(i + 1 < R.size() && x.fi == R[i + 1].fi){
                        continue;
                }

                if(t[1].fi - x.fi > best){
                        best = t[1].fi - x.fi;
                        res = {t[1].se, x.fi};
                }
        }

        cout << best << "\n";
        cout << res.fi << " " << res.fi << " " << res.se << " " << res.se << "\n";
}