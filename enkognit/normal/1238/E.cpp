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
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

ll n, m, it, i, p, k, T, j, a[2000001], B, C, y, kol, d[30][30];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < s.size()-1; i++)
        if (s[i]!=s[i+1])
        {
            d[s[i]-'a'][s[i+1]-'a']++;
            d[s[i+1]-'a'][s[i]-'a']++;
        }
    vector <ll> dp((1<<m)+5, 1e18);
    //cout << dp[(1<<m)-1] << "\n";
    dp[0]=0;
    for (int i = 0; i < (1<<m); i++)
    {
        vector <ll> v1, v0;
        ll z=i, o=0;
        while (o<m)
        {
            if (z%2) v1.pb(o); else v0.pb(o);
            o++;
            z/=2;
        }
        ll q=0;
        for (int j = 0; j < v1.size(); j++)
            for (int u = 0; u < v0.size(); u++)
                q+=d[v1[j]][v0[u]];
        for (int j = 0; j < m; j++)
            if ((i&(1<<j))==0)
            {
                dp[i^(1<<j)]=min(dp[i^(1<<j)], q+dp[i]);
            }
    }
    cout << dp[(1<<m)-1];
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