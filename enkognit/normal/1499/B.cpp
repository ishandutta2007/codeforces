#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, sm;
bool pr[10001], sf[10001];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

void solve()
{
    string s;
    //cin >> n;
    cin >> s;
    n=s.size();
    s=' '+s;
    for (int i = 1; i <= n; i++)
    {
        pr[i]=pr[i-1];
        pr[i]|=(s[i]==s[i-1] && s[i]=='1');
    }
    sf[n]=0;
    for (int i = n-1; i > 0; i--)
    {
        sf[i]=sf[i+1];
        sf[i]|=(s[i]==s[i+1] && s[i]=='0');
    }
    for (int i = 1; i <= n; i++)
        if (!pr[i] && !sf[i+1])
        {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}