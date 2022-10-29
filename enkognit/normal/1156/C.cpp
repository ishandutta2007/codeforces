#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=998244353;

ll n, m, w, l, r, T, k, sum, a[1000001], p[1000001];
vector <ll> v, o;
string s;

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector <ll> a;
    a.pb(-1);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    ll l=0, r=n/2;
    while (l < r)
    {
        ll w=(l+r)/2+(l+r)%2;
        bool tt=1;
        for (int i = 1; i <= w; i++)
            if (abs(a[i]-a[n-w+i])<m) tt=0;
        if (tt) l=w; else r=w-1;
    }
    cout << l;
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4

*/