#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, q, ans, l, r, i, j;
vector <ll> c[100008], v, z;
ll t[1000001],u[1000001];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> n;
        ll l=0, r=0;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x>l) swap(l,r),l=x; else
            if (x>r) r=x;
        }
        cout << min(r-1,n-2) << "\n";
    }
    return 0;
}