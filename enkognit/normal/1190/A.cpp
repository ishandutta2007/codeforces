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

ll n, m, k, p, ans, l, r, i, j, a[500005];
pll b[200005];
vector <ll> c[300001], v;
string s, d;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> a[i];
    ll st=1, ans=0, p=0;
    v.pb(0);
    for (int i = 1; i <= m; i++)
    {
        st=(a[i]-p)/k+(((a[i]-p)%k)>0);
        ll j=i;
        while (a[j]<=st*k+p) j++;
        ans++;
        p+=j-i;
        i=j-1;
    }
    cout << ans;
    return 0;
}