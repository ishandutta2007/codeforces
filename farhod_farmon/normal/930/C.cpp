#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
int a[N];
int l[N];
int r[N];
int t[4 * N];

void build(int x, int l, int r)
{
        t[x] = 0;
        if(l == r){
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
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
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        }
        if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int l, r;
                cin >> l >> r;
                a[l]++;
                a[r + 1]--;
        }
        if(m == 1){
                cout << 0 << "\n";
                return;
        }
        for(int i = 1; i <= m; i++){
                a[i] += a[i - 1];
        }
        for(int i = 1; i <= m; i++){
                l[i] = get(1, 0, n, 0, a[i]) + 1;
                upd(1, 0, n, a[i], l[i]);
        }
        build(1, 0, n);
        for(int i = m; i >= 1; i--){
                r[i] = get(1, 0, n, 0, a[i]) + 1;
                upd(1, 0, n, a[i], r[i]);
        }
        int ans = 0;
        for(int i = 1; i <= m; i++){
                ans = max(ans, l[i] + r[i] - 1);
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}