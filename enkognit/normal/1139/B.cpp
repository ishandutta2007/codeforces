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
bool t[100001];
string s;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    b[n-1]=a[n-1];
    for (int i = n-2; i > -1; i--)
    {
        b[i]=max(min(a[i],b[i+1]-1),0ll);
        ans+=b[i];
    }
    cout << ans+a[n-1];
    return 0;
}