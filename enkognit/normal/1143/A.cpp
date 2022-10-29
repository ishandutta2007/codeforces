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

ll n, m, i, j, k, l, r, a[500001];
pll b[500001];
string s, d;
vector <ll> v;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    ll k1=0,k2=0;
    for (int i = 0; i < n; i++) {cin >> a[i];k1+=(a[i]==1);k2+=(a[i]==0);}
    for (int i = 0; i < n; i++)
    {
        k1-=(a[i]==1);k2-=(a[i]==0);
        if (k1==0 || k2==0) {cout << i+1;exit(0);}
    }
    return 0;
}