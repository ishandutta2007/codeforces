#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 300300;
const int MAGIC = sqrt(N);
const long long mod = 5e7 + 17;

using namespace std;

ll n;
ll cnt;
ll f[1111];
ll s[1111];

void rec(ll x, ll g)
{
    if(x == 1){
        f[g] = s[g] = 1;
        return;
    }
    rec(x / 2, g + 1);
    f[g] = f[g + 1] * 2 + 1;
    s[g] = s[g + 1] * 2 + x % 2;
}

void sol(ll x, ll g, ll l, ll r, ll tl, ll tr)
{
    if(tl > tr)
        return;
    if(l == tl && tr == r){
        cnt += s[g];
        return;
    }
    sol(x / 2, g + 1, l, l + f[g + 1] - 1, tl, min(l + f[g + 1] - 1, tr));
    sol(x / 2, g + 1, r - f[g + 1] + 1, r, max(r - f[g + 1] + 1, tl), tr);
    if(x % 2 == 1 && l + f[g + 1] <= tr && tl <= l + f[g + 1])
        cnt++;
}

void solve()
{
    ll l, r;
    cin >> n >> l >> r;
    if(n == 0){
        cout << 0 << endl;
        return;
    }
    rec(n, 0);
    sol(n, 0, 1, f[0], l, r);
    cout << cnt << endl;
}


bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}