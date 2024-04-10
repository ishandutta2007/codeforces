#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int inf = 1e9;

struct node
{
        pair < int, int > a[9];
        node(){
                for(int i = 0; i < 9; i++){
                        a[i] = {inf, inf};
                }
        }
};

node make(int x)
{
        int y = x;
        node res;
        vector < int > v;
        while(x){
                v.push_back(x % 10);
                x /= 10;
        }
        while(v.size() < 9){
                v.push_back(0);
        }
        reverse(v.begin(), v.end());
        for(int i = 0; i < 9; i++){
                if(v[i]){
                        res.a[i] = {y, inf};
                }
        }
        return res;
}

node comb(node x, node y)
{
        node res;
        for(int i = 0; i < 9; i++){
                res.a[i] = x.a[i];
                for(int z: {y.a[i].fi, y.a[i].se}){
                        if(z < res.a[i].fi){
                                res.a[i].se = res.a[i].fi;
                                res.a[i].fi = z;
                        } else if(z < res.a[i].se){
                                res.a[i].se = z;
                        }
                }
        }
        return res;
}

int n;
int m;
int a[N];

node t[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = make(a[l]);
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

void upd(int x, int l, int r, int g, int y)
{
        if(l == r){
                t[x] = make(y);
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g, y);
        } else{
                upd(x * 2 + 1, m + 1, r, g, y);
        }
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

node get(int x, int l, int r ,int tl, int tr)
{
        if(tl > tr){
                node em;
                return em;
        } else if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        build(1, 1, n);
        for(int i = 1; i <= m; i++){
                int t, l, r;
                cin >> t >> l >> r;
                if(t == 1){
                        upd(1, 1, n, l, r);
                } else{
                        auto res = get(1, 1, n, l, r);
                        int best = inf + inf;
                        for(int i = 0; i < 9; i++){
                                if(res.a[i].se == inf){
                                        continue;
                                }
                                best = min(best, res.a[i].fi + res.a[i].se);
                        }
                        if(best == inf + inf){
                                cout << -1 << "\n";
                        } else{
                                cout << best << "\n";
                        }
                }
        }
}