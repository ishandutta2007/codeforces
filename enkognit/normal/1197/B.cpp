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
ll t[1000001],a[1000001];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll tt=0;
    for (int i = 0; i < n-1; i++)
    {
        if (a[i]<a[i+1])
        {
            if (tt>0) {cout << "NO\n";exit(0);}
        }
        if (a[i]>a[i+1])
        {
            if (tt==0) tt++;
        }
    }
    sort(a,a+n);
    for (int i = 0; i < n-1; i++)if (a[i]==a[i+1]) {cout << "NO\n";exit(0);}
    cout << "YES\n";
    return 0;
}