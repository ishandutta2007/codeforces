#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500500;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int l[N];
int r[N];
int ans[N];
int used[N];
pair < int, int > t[4 * N];

void upd(int x, int l, int r, int g, int y)
{
        if(l == r){
                t[x] = {y, a[l]};
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g, y);
        }
        else{
                upd(x * 2 + 1, m + 1, r, g, y);
        }
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

pair < int, int > get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return {0, 0};
        }
        if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                l[i] = used[a[i]];
                used[a[i]] = i;
        }
        for(int i = 1; i < N; i++){
                used[i] = n + 1;
        }
        vector < pair < int, pair < int, int > > > v;
        for(int i = n; i >= 1; i--){
                r[i] = used[a[i]];
                used[a[i]] = i;
                v.push_back({l[i], {r[i], i}});
        }
        sort(v.begin(), v.end());
        int q;
        cin >> q;
        vector < pair < int, pair < int, int > > > qu;
        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                qu.push_back({l, {r, i}});
        }
        sort(qu.begin(), qu.end());
        int h = 0;
        for(auto p: qu){
                while(h < v.size() && v[h].fi < p.fi){
                        upd(1, 1, n, v[h].se.se, v[h].se.fi);
                        h++;
                }
                auto g = get(1, 1, n, p.fi, p.se.fi);
                if(g.fi > p.se.fi){
                        ans[p.se.se] = g.se;
                }
        }
        for(int i = 1; i <= q; i++){
                cout << ans[i] << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}