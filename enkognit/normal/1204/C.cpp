#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
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

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, a[1000001], dp[105][105];
string s;
vector <ll> c[1001];
ll t[1001];

void dfs(ll h,ll k,ll pr)
{
    t[h]=k;
    dp[pr][h]=k;
    //cout << h << " " << k << " " << pr << "\n";
    for (int i = 0; i < c[h].size(); i++)
        if (t[c[h][i]]>t[h]+1) dfs(c[h][i],k+1,pr);
}

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j]=='1')
            c[i].pb(j+1);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    vector <ll> v={};
    v.pb(a[0]);
    for (int i = 0; i <= n; i++) {for (int j = 0; j <= n; j++) t[j]=1e18;dfs(i,0,i);}
    for (int i = 1; i < m-1; i++)
    {
       // bool tt=0;
       //cout << dp[v[v.size()-1]][a[i+1]] << " " << dp[v[v.size()-1]][a[i]] << "\n";
        if (dp[v[v.size()-1]][a[i+1]]<=dp[v[v.size()-1]][a[i]]) v.pb(a[i]);
    }
    v.pb(a[m-1]);
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/