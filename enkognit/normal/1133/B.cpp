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
ll v[5002];
map <ll,ll> t;
string s,d;

int main()
{
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        t[a[i]%k]++;
    }
    ll ans=t[0]/2*2;
    //cout << t[0] << " " << t[1] << "\n";
    for (int i = 1; i <= k/2; i++) if (i!=k-i)ans+=min(t[i],t[k-i])*2; else ans+=t[i]/2*2;
    cout << ans;
    return 0;
}