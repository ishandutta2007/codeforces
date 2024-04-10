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
int c[N];
int f[N];
int t[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = 1;
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = t[x * 2] + t[x * 2 + 1];
}

void upd(int x, int l, int r, int g)
{
        if(l == r){
                t[x] = 0;
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g);
        }
        else{
                upd(x * 2 + 1, m + 1, r, g);
        }
        t[x] = t[x * 2] + t[x * 2 + 1];
}

int get(int x, int l, int r, int k)
{
        if(l == r){
                return l;
        }
        int m = (l + r) / 2;
        if(t[x * 2] >= k){
                return get(x * 2, l, m, k);
        }
        else{
                return get(x * 2 + 1, m + 1, r, k - t[x * 2]);
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                f[i] = max(f[i - 1], c[i]);
        }
        long long ans = 0;
        int F = f[n] + 1, g = f[n] + 1;
        build(1, 1, F);
        for(int i = n; i >= 1; i--){
                ans += g - c[i] - 1;
                if(f[i - 1] + 1 < g){
                        upd(1, 1, F, get(1, 1, F, g - c[i]));
                        g--;
                }
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