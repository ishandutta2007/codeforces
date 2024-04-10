#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, i, j, m, ans, k, q, l, r, z, a[500001];
ll b[500001];
vector <ll> v;
vector <ll> c[100001];
ll t[100001];
string s;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        t[a[i]]++;
        if (a[i]>=i) k++;
        k-=t[i];
        t[i]=0;
        if (!k) ans++;
        //cout << k << "\n";
    }
    cout << ans;
    return 0;
}