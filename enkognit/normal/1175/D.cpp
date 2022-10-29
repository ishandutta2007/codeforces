#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, x, k, a[300005], ans, d[2000001];


int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> n >> k;
    ll z=0;
    for (int i = 1; i <= n; i++) {cin >> a[i];z+=a[i];}
    for (int i = n-1; i > 0; i--) a[i]+=a[i+1];
    a[0]=-1e18;
    vector <ll> v;
    for (int i = 2; i <= n; i++) v.pb(a[i]);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (int i = 0; i < k-1; i++) z+=v[i];
    cout << z;
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/