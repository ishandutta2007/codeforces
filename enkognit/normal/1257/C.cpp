#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, kol=0, T=0, mask, a[1000001];
vector <ll> v;
string s;
ll tt[200001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 1; i <=n; i++) tt[i]=0;
        ll ans=1e18;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (tt[a[i]]>0) ans=min(ans,i-tt[a[i]]+1);
            tt[a[i]]=i;
        }
        if (ans==1e18) cout << "-1\n"; else
        cout << ans << "\n";
    }

    return 0;
}
/*
3 2
0 1
1 2
1 2
2 3
2 3
3 4
1 2
2 3
*/