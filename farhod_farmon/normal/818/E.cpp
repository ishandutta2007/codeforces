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
const long long MX = 1000010;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
ll k;
ll a[N];
ll t[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = __gcd(a[l], k);
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = __gcd(t[x * 2] * t[x * 2 + 1], k);
}

ll get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        }
        if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        ll a = get(x * 2, l, m, tl, min(m, tr));
        ll b = get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
        if(!a) return b;
        if(!b) return a;
        return __gcd(a * b, k);
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        build(1, 1, n);
        ll ans = 0;
        for(int i = 1, j = 0; i <= n; i++){
                while(get(1, 1, n, j + 1, i) == k){
                        j++;
                }
                ans += j;
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                sc("%d", &TE);
        while(TE--)
                solve();
        return 0;
}