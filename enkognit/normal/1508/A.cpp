#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
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

ll n, m, k, sz, l[3];
string s[3];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < 3; i++)l[i]=0;
    string d;
    while(l[0]<2*n && l[1]<2*n && l[2]<2*n)
    {
        ll kl0=0, kl1=0;
        for (int i = 0; i < 3; i++)
            if (s[i][l[i]]=='0') kl0++; else kl1++;
        //cout << kl0 << " " << kl1 << "\n";
        if (kl0>kl1)
        {
            for (int i = 0; i < 3; i++)
                if (s[i][l[i]]=='0') l[i]++;
            d+='0';
        }
        else
        {
            for (int i = 0; i < 3; i++)
                if (s[i][l[i]]=='1') l[i]++;
            d+='1';
        }
    }
    vector<pll> v;
    for (int i = 0; i < 3; i++)
        v.pb(mp(l[i], i));
    sort(all(v));
    while (l[v[1].se]<2*n)
    {
        d+=s[v[1].se][l[v[1].se]];
        l[v[1].se]++;
    }
    cout << d << "\n";
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
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/