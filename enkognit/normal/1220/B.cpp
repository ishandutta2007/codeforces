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
#define y1 Enkognit

using namespace std;

const ll MOD = 998244353;

ll n, k, l, m, r, i, j, x, y, ans, a[1001][1001];
vector <ll> v;
ll c[50];
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    v.pb(0);
    for (int i = 1; i < n-1; i++)
    {
        v.pb((ll)sqrt(a[i-1][i]*a[i][i+1]/a[i-1][i+1]));
    }
    v.pb(0);
    v[0]=a[0][1]/v[1];
    v[n-1]=a[n-1][n-2]/(ll)v[n-2];
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}
/*
6 15
E 5
V 9
M 3
V 2
M 5
V 6
*/