#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

const ll MOD = 998244353;

ll n, m, k, q, p, ans, l, r, i, j, x, y;
ll a[500001];
bool t[1000001];
string s;
vector <ll> v;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for (int i = n/2; i < n; i++) v.pb(a[i]);
    ll l=0;
    while (k)
    {
        while (l+1<v.size() && v[l]==v[l+1]) l++;
        if (l==v.size()-1)
        {
            cout << v[l]+k/v.size() << "\n";
            exit(0);
        }else
        if ((v[l+1]-v[l])*(l+1)<=k)
        {
            k-=(v[l+1]-v[l])*(l+1);
            l++;
        }else
        {
            cout << v[l]+k/(l+1) << "\n";
            exit(0);
        }
    }
    while (l+1<v.size() && v[l]==v[l+1]) l++;
    cout << v[l];
    return 0;
}


/*

| 1 5 13 29 | 2 7 17 37 | 18 39 22 47 |


*/