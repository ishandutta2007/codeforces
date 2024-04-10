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
vector <ll> v;
map<ll,ll> c;
string s, d;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> a[i];c[a[i]]++;}
    sort(a,a+n);
    ll o=0, p=1, z=0;
    if (a[0]==0 && a[1]==0) {cout << "cslnb\n";exit(0);}
    for (int i = 1; i < n; i++)
    {
        if (a[i]==a[i-1]) p++; else
        p=1;
        if (p==2) {z++;if (c[a[i]-1]>0) {cout << "cslnb\n";exit(0);}}
        if (p>2) {cout << "cslnb\n";exit(0);}
    }
    if (z>1) {cout << "cslnb\n";exit(0);}
    for (ll i = 0; i < n; i++)
    {
        if (a[i]-i<0) {cout << "cslnb\n";exit(0);}
        o+=a[i]-i;
    }
    if (o%2) cout << "sjfnb\n"; else {cout << "cslnb\n";exit(0);}
    return 0;
}