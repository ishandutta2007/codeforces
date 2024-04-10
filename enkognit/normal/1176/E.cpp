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

ll n, m, i, j, x, k, ans, b[200005];
ll a[200005];
string s, d;
vector <ll> v, c[200003];
bool tt[200001];

ll dfs(ll h,ll k)
{
    if (k%2==0) v.pb(h);
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++) if (!tt[c[h][i]]) dfs(c[h][i],k+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    //ll x, y, z;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) c[i].clear(), tt[i]=0;

        for (int i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            c[x].pb(y);
            c[y].pb(x);
        }
        v.clear();
        dfs(1,0);
        if (v.size()>n/2)
        {
            //cout << v.size() << "\n";
            cout << n-v.size() << "\n";
            for (int i = 0; i < v.size(); i++) tt[v[i]]=0;
            for (int i = 1; i <= n; i++) if (tt[i]) cout << i << " ";
            cout << "\n";
        }
         else
        {
            cout << v.size() << "\n";
            for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/