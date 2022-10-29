#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, i, j, a[1001][1001];
vector <ll> v, z;
string s, d;

ll binpow(ll k,ll h)
{
    ll l=1, r=h, x=k;
    while (r)
    {
        if (r%2) l*=x, l%=MOD;
        x*=x;
        x%=MOD;
        r/=2;
    }
    return l;
}

int main()
{
    cin >> n;
    ll T=0;
    for (int i = 1; i <= n; i++)
    {
        if (i%2)
        {for (int j = 1; j <= n; j++) T++,a[j][i]=T;}
        else
        {for (int j = n; j > 0; j--) T++,a[j][i]=T;}
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}