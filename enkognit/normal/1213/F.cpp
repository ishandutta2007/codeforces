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

ll n, m, k, q, l, r, i, j, x, y, ans, a[300001], b[300001];
ll tt[300001];
ll z[300001];
char c[300001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll p=0;
    for (int i = 0; i < n; i++)
    {
        if (tt[a[i]]) p--; else p++;
        tt[a[i]]++;
        if (tt[b[i]]) p--; else p++;
        tt[b[i]]++;
        if (p==0) z[i]=1;
    }
    ll r=0;
    for (int i = 0; i < n; i++)
    {
        c[a[i]]=r+'a';
        r+=z[i];
        if ((r+'a'>'z' && i<n-1) || r>m) r--;
    }
    if (r>=m) {cout << "YES\n";for (int i = 1; i <= n; i++) cout << c[i];} else cout <<"NO\n";
    return 0;
}
/*
10 3
9 30 45 2 5 7 10 3 16 22
*/