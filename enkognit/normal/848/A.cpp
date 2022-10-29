#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pll pair<ll,ll>
#define y1 Enkognit
#define fi first
#define se second
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k, x, y, a[1000001], dp[1000001][2];
string s;

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h,l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

vector<pll> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 'a'; i <= 'z'; i++) s+=i, a[i-'a']=1;
    for (int i = 0; i < 'z'-'a'; i++)
    {
        while (n>=a[i]) n-=a[i], a[i]++, s+=(char)(i+'a');
    }
    cout << s;
    return 0;
}