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
vector <ll> c[300005];
map<ll, ll> t;
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    cin >> n;
    for (int x = 1; x <= sqrt(n); x++)
    {
        ll m=n-x*x-x-1;
        if (m<=0)continue;
        if (m%x) continue;
        m/=x;
        if (m%2) continue;
        m/=2;
        cout << x << " " << m << "\n";
        exit(0);
    }
    cout << "NO\n";
    return 0;
}