#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

const ll mod=1e9+7;

ll n, m, i, j, v, r, p, k, ans, a[500001];
string s;
map<ll,ll> t;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    ll l=1e18;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        l=min(l,a[i]);
        k+=a[i];
    }
    ll ans=k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j <= sqrt(a[i]); j++)
            if (a[i]%j==0)
        {
            ans=min(ans,k-a[i]-l+a[i]/j+l*j);
            ans=min(ans,k-a[i]-l+j+l*a[i]/j);
        }
    }
    cout << ans;
    return 0;
}