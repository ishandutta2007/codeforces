#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500500;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a[N];
int t[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = a[l];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] =  __gcd(t[x * 2], t[x * 2 + 1]);
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
        }
        else{
                upd(x * 2 + 1, m + 1, r, g, y);
        }
        t[x] = __gcd(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r, int tl, int tr, int g)
{
        if(tl > tr || t[x] % g == 0){
                return 0;
        }
        if(l == r){
                return 1;
        }
        int m = (l + r) / 2;
        int c = get(x * 2, l, m, tl, min(m, tr), g);
        if(c < 2){
                c += get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
        }
        return c;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        build(1, 1, n);
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int t, l, r, x;
                cin >> t >> l >> r;
                if(t == 1){
                        cin >> x;
                        if(get(1, 1, n, l, r, x) < 2){
                                cout << "YES" << "\n";
                        }
                        else{
                                cout << "NO" << "\n";
                        }
                }
                else{
                        upd(1, 1, n, l, r);
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}