#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 600300;
const int MAGIC = 1000;
const long long mod = 998244353;

using namespace std;

int n;
int t[4 * N];
pair < int, int > a[N];

int comb(int x, int y)
{
        if(!x || !y){
                return x + y;
        }
        if(a[x].se > a[y].se){
                return x;
        }
        return y;
}

void upd(int x, int l, int r, int g, int y)
{
        if(g < 0){
                g += 2 * n + 1;
        }
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
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r, int tl, int tr)
{
        if(tr < 0){
                tr += 2 * n + 1;
        }
        if(tl > tr){
                return 0;
        }
        if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

vector < int > solve(vector < int > v)
{
        for(int i = 1; i < 4 * N; i++){
                t[i] = 0;
        }
        for(auto p: v){
                upd(1, 1, 2 * n, a[p].fi, p);
        }
        vector < int > res;
        int last = get(1, 1, 2 * n, 1, 2 * n);
        while(last){
                res.push_back(last);
                upd(1, 1, 2 * n, a[last].fi, 0);
                last = get(1, 1, 2 * n, 1, a[last].se);
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < int > A, B;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi >> a[i].se;
                if(a[i].fi > a[i].se){
                        B.push_back(i);
                        a[i].fi *= -1;
                        a[i].se *= -1;
                } else{
                        A.push_back(i);
                }
        }
        auto va = solve(A);
        auto vb = solve(B);
        if(va.size() < vb.size()){
                va = vb;
        }
        cout << va.size() << "\n";
        for(int x: va){
                cout << x << " ";
        }
}