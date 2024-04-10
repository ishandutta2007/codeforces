#include <bits/stdc++.h>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double

using namespace std;

ld PI=3.14159265359, sec_clock=1e8;

ll n, m, l, r, k, h, i, j, T;
ll a[500001];
vector <ll> v;
map <ll,ll> t;
string s,d;

int main()
{
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.pb(x);
    }
    ll ans=0;
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)
    {
        ll l=i,r=n-1;
        while (l<r)
        {
            ll w=(l+r)/2+(l+r)%2;
            if (v[w]<=v[i]+5) l=w; else r=w-1;
        }
        ans=max(ans,l-i+1);
    }
    cout << ans;
    return 0;
}