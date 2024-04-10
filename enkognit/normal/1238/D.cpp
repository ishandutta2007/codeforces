#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

const ll MOD=1e9+7;

ll n, m, it, i, p, k, T, j, A, in[100001], out[100001], B, C, y, kol, d[1000001];pll bn[100001][30];
vector <pll> c[100001], z[100001];
string s;
bool tt[100001], t[100001];

int main()
{
    cin >> n;
    cin >> s;
    ll ans=n*(n-1)/2;
    vector <ll> a, b;
    a.pb(-1);
    b.pb(-1);
    for (int i = 0; i < n; i++)
    {
        if (i+1<n && s[i]!=s[i+1]) ans++;
        if (s[i]=='A') a.pb(i);
        if (s[i]=='B') b.pb(i);
    }
    a.pb(s.size());
    b.pb(s.size());
    for (int i = 1; i < a.size()-1; i++)
    {
        ans-=a[i+1]-a[i]-1+a[i]-a[i-1]-1;
    }
    for (int i = 1; i < b.size()-1; i++)
    {
        ans-=b[i+1]-b[i]-1+b[i]-b[i-1]-1;
    }
    cout << ans;
}

/*
9 12
1 9 4
1 2 5
2 3 7
2 4 3
4 3 6
3 6 4
8 7 10
6 7 5
5 8 1
9 5 7
5 4 12
6 8 2
2
4 7
5
1 6
5 3
4 8
5 8
1 5
*/