#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

struct lev
{
        long long res, mn, mx;
        lev()
        {
                res = 0;
                mn = 1e18;
                mx = -1e18;
        }
        void make(long long x)
        {
                mn = mx = x;
        }
};

lev comb(lev x, lev y)
{
        x.res = max(x.res, y.res);
        x.res = max(x.res, y.mx - x.mn);
        x.mn = min(x.mn, y.mn);
        x.mx = max(x.mx, y.mx);
        return x;
}

int n;
long long A;
long long s[N];
long long d[N];
lev t[4 * N];
int f[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                t[x].make(l * A - s[l]);
                if(l == 0 || l == n){
                        f[x] = 1;
                }
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        f[x] = f[x * 2] + f[x * 2 + 1];
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

void upd(int x, int l, int r, int g)
{
        if(l == r){
                f[x] = 1;
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g);
        }
        else{
                upd(x * 2 + 1, m + 1, r, g);
        }
        f[x] = f[x * 2] + f[x * 2 + 1];
}

int get_left(int x, int l, int r, int g)
{
        if(g < l || !f[x]){
                return -1;
        }
        if(l == r){
                return l;
        }
        int m = (l + r) / 2;
        int res = get_left(x * 2 + 1, m + 1, r, g);
        if(res == -1){
                return get_left(x * 2, l, m, g);
        }
        return res;
}

int get_right(int x, int l, int r, int g)
{
        if(g > r || !f[x]){
                return -1;
        }
        if(l == r){
                return l;
        }
        int m = (l + r) / 2;
        int res = get_right(x * 2, l, m, g);
        if(res == -1){
                return get_right(x * 2 + 1, m + 1, r, g);
        }
        return res;
}

lev get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return lev();
        }
        if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> A;
        vector < pair < long long, int > > v;
        for(int i = 1; i <= n; i++){
                cin >> d[i] >> s[i];
                s[i] += s[i - 1];
                if(i > 1){
                        v.push_back({(d[i] - d[i - 1]) * (d[i] - d[i - 1]), i - 1});
                }
        }
        build(1, 0, n);
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        long long res = 0;
        for(int i = 0; i < v.size(); i++){
                int x = v[i].se;
                int l = get_left(1, 0, n, x), r = get_right(1, 0, n, x);
                res = max(res, get(1, 0, n, l, r).res - v[i].fi);
                upd(1, 0, n, x);
        }
        for(int i = 1; i <= n; i++){
                res = max(res, A - s[i] + s[i - 1]);
        }
        cout << res << "\n";
}