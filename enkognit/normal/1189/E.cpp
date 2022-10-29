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

ll n, m, k, p, ans, l, r, i, j, k1, k0, a[100001];
map<ll, ll> t;
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    cin >> n >> p >> k;
    for (int i = 0; i < n; i++)
    {
        ll v;
        cin >> v;
        ll o=((v*v%p*v%p*v%p-k*v)%p+p)%p;
        ans+=t[o];
        t[o]++;;
    }
    cout << ans;
    return 0;
}