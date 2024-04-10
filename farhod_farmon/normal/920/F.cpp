#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int q;
int a[N];
int c[Q];
int t[4 * N];
long long s[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                s[x] = t[x] = a[l];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        s[x] = s[x * 2] + s[x * 2 + 1];
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

void upd(int x, int l, int r, int tl, int tr)
{
        if(t[x] < 3 || tl > tr){
                return;
        }
        if(l == r){
                s[x] = t[x] = a[l] = c[a[l]];
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr));
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
        s[x] = s[x * 2] + s[x * 2 + 1];
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

long long get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        }
        if(l == tl && r == tr){
                return s[x];
        }
        int m = (l + r) / 2;
        return get(x * 2, l, m, tl, min(m, tr)) + get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

void solve()
{
        for(int i = 1; i < Q; i++){
                for(int j = i; j < Q; j += i){
                        c[j]++;
                }
        }
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        build(1, 1, n);
        for(int i = 1; i <= q; i++){
                int t, l, r;
                cin >> t >> l >> r;
                if(t == 1){
                        upd(1, 1, n, l, r);
                }
                else{
                        cout << get(1, 1, n, l, r) << "\n";
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