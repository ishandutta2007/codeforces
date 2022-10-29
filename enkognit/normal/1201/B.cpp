#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

const ll MOD = 998244353;

ll n, m, k, q, p, ans, l, r, i, j, x, y;
ll a[500001];
bool t[1000001];
string s;
vector <ll> v;

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
        l+=a[i];
    }
    sort(a,a+n);
    if (l%2 || a[n-1]>l-a[n-1]) {cout << "NO\n";exit(0);}
    cout << "YES\n";
    return 0;
}


/*

| 1 5 13 29 | 2 7 17 37 | 18 39 22 47 |


*/