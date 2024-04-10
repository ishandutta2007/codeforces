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

int n, m, it, i, p, k, T, j, A, B, C, y, kol, b[200001], f[1000001], a[200001];

bool tt[200001];

ll get(ll h)
{
    ll ans=0;
    for (int i = h; i > 0; i-=(i&-i)) ans+=f[i];
    return ans;
}

void update(ll h)
{
    for (int i = h; i <= 100000; i+=(i&-i)) f[i]++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i+1];
    }
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        b[x]=i+1;
    }
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        //cout << a[i] << " " << b[a[i]] << " ";
        ll o=get(b[a[i]]);
        if (i-1>o) ans++;
        //cout << o << "\n";
        update(b[a[i]]);
    }
    cout << ans << "\n";
}

/*
5 4 4
1 2
3 1
3 4
5 3
4 5 2 3
2 1 3 1
1 3 5
2 3 4 5
2 1 3 1
*/