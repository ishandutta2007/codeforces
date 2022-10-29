#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second

using namespace std;

ll n, m, i, j, k, l, r, a[1000001];
string s, d;
vector <ll> v, c[300001];
bool t[1000001];

int main()
{
    cin >> n >> m >> k;
    ll p=0, l=n%k, r=m%k;
    if (l==0) l=k;
    if (r==0) r=k;
    if (m%k+n%k<k) p=0; else
    p=min(k-l,k-r);
    cout << (n+m)/k << " " << p;
}