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

ll n, i, j, m, ans, k, q, l, r, z;
ll a[500001], b[500001];
int t[500001];
multiset<ll> s;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) cin >> a[i];
    b[i]=1;
    ll o=1;
    for (int i = 0; i < n-1; i++) {b[i+1]=b[i]+a[i];o=min(o,b[i+1]);}
    for (int i = 0; i < n; i++)
    {
        b[i]=b[i]-o+1;
        if (b[i]<1) {cout << -1;exit(0);}
        if (b[i]>n) {cout << -1;exit(0);}
        t[b[i]]++;
        if (t[b[i]]!=1){cout << -1;exit(0);}
    }
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    return 0;
}