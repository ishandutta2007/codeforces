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

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

ll n, m, T, k, l, r, i, j, sum, kol=0;
map<string,bool> w;
vector <ll> c[201];
bool tt[101], tl[101];

void dfs(ll h)
{
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]]) dfs(c[h][i]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll mask=0;
    bool t[50]={};
   for (int i = 0; i < n; i++)
   {
       string s;
       cin >> s;
       vector <ll> p;
       for (int j = 0; j < 26; j++) t[j]=0;
       for (int j = 0; j < s.size(); j++)
            if (!t[j])
            {
                t[j]=1;
                p.pb(s[j]-'a');
                tl[s[j]-'a']=1;
            }
            //cout << p[i].size() << "\n";
        sort(p.begin(),p.end());
        for (int u = 0; u < p.size(); u++)
            for (int j = 0; j < p.size(); j++) if (u!=j) c[p[u]].pb(p[j]);
       // cout << o << "\n";
    }
    ll ans=0;
    for (int i = 0; i < 26; i++) if (!tt[i] && tl[i]) {dfs(i);ans++;}
    cout << ans;
    return 0;
}
/*
5 6
X...XX
XX...X
......
..XX..
XXX..X
*/