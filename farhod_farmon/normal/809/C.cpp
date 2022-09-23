#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 30030;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int q;
ll ans;

ll f(ll x)
{
        return (x * (x + 1) / 2) % mod;
}

int k;

void go(int l1, int r1, int l2, int r2, int l, int r, int x2, int y2, int g, int need, int h1, int h2)
{
        if(x2 > y2 || l > k){
                return;
        }
        if(need == g || l2 == x2 && r2 == y2){
                ll col = min(r1 - l1 + 1, y2 - x2 + 1);
                ll s = f(min(k, r)) - f(l - 1);
                s = (s % mod + mod) % mod;
                s = s * col % mod;
                ans = (ans + s) % mod;
                return;
        }
        int m = l2 + (1 << g) - 1;
        int m2 = h1 + (1 << g) - 1;
        if(l1 > m2){
                go(l1, r1, l2, m, l + (1 << g), r, x2, min(y2, m), g - 1, need, m2 + 1, h2);
                go(l1, r1, m + 1, r2, l, l + (1 << g) - 1, max(m + 1, x2), y2, g - 1, need, m2 + 1, h2);
        }
        else{
                go(l1, r1, l2, m, l, l + (1 << g) - 1, x2, min(y2, m), g - 1, need, h1, m2);
                go(l1, r1, m + 1, r2, l + (1 << g), r, max(m + 1, x2), y2, g - 1, need, h1, m2);
        }
}

void go1(int l, int r, int x1, int y1, int x2, int y2, int g)
{
        if(x1 > y1){
                return;
        }
        if(l == x1 && r == y1){
                //cout << x2 << " " << y2 << endl;
                go(l, r, 1, (1 << 30), 1, (1 << 30), x2, y2, 29, g, 1, (1 << 30));
                return;
        }
        int m = l + (1 << g) - 1;
        go1(l, m, x1, min(m, y1), x2, y2, g - 1);
        go1(m + 1, r, max(m + 1, x1), y1, x2, y2, g - 1);
}

void solve()
{
        cin >> q;
        //k = 100;
        //go(5, 5, 1, 8, 1, 8, 2, 4, 2, -1);
        //return;
        for(int i = 1; i <= q; i++){
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2 >> k;
                ans = 0;
                go1(1, (1 << 30), x1, x2, y1, y2, 29);
                cout << ans << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}