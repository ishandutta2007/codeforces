#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

struct node
{
        int pref, suf, sz;
        long long res;
        node() : pref(1), suf(1), res(1), sz(1) {}
        node(int a, int b, int c, int d) : pref(a), suf(a), res(c), sz(d) {}
};

int n, q;
int a[N];
node t[4 * N];

node comb(node L, node R, int x, int y)
{
        node res;
        res.sz = L.sz + R.sz;
        res.res = L.res + R.res;
        res.pref = L.pref;
        res.suf = R.suf;

        if(x > y){
                return res;
        }

        res.res += 1ll * L.suf * R.pref;
        if(R.sz == R.pref){
                res.suf += L.suf;
        }
        if(L.sz == L.suf){
                res.pref += R.pref;
        }

        return res;
}

void build(int x, int l, int r)
{
        if(l == r){
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = comb(t[x * 2], t[x * 2 + 1], a[m], a[m + 1]);
}

void upd(int x, int l, int r, int g)
{
        if(l == r){
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g);
        } else{
                upd(x * 2 + 1, m + 1, r, g);
        }
        t[x] = comb(t[x * 2], t[x * 2 + 1], a[m], a[m + 1]);
}

node get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return node(0, 0, 0, 0);
        } else if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr), a[m], a[m + 1]);
}

void solve()
{
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }

        build(1, 1, n);
        for(int i = 0; i < q; i++){
                int t, x, y;
                cin >> t >> x >> y;
                if(t == 1){
                        a[x] = y;
                        upd(1, 1, n, x);
                } else{
                        cout << get(1, 1, n, x, y).res << "\n";
                }
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t = 1;
        //cin >> t;
        while(t--){
                solve();
        }
}