#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 shue_ppsh
#define all(a) a.begin(),a.end()

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, kl, j, x, a[1000001];
string s, d;
bool tt[1001];
vector<ll> c[1001];

void dfs(int h)
{
    tt[h]=1;
    d+=h;
    //cout << (char)h;
    kl++;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]]) dfs(c[h][i]);
}

void solve()
{
    cin >> s;
    //cout << "1\n";
    for (int i = 'a'; i <= 'z'; i++)
    {
        tt[i]=0;
        c[i].clear();
    }
    vector<ll> v;
    v.clear();
    ll lst=0;
    kl=0;
    for (int i = 0; i < s.size()-1; i++)
    {
        bool t=0;
        for (int j = 0; j < c[s[i]].size(); j++)
            if (c[s[i]][j]==s[i+1]) t=1;
        if (!t) {c[s[i]].pb(s[i+1]);c[s[i+1]].pb(s[i]);}
    }
    ll o=-1;
    d="";
    //cout << "-----\n";
    for (int i = 'a'; i <= 'z'; i++)
    {
        tt[i]=0;
        if (c[i].size()>2) {cout << "NO\n";return;}
    }
    //cout << "YES\n";
    //cout << o << "\n";
    for (int i = 'a'; i <= 'z'; i++) tt[i]=0;
    //cout << o << "\n";
    for (int i = 'a'; i <= 'z'; i++) if (c[i].size()<2 && !tt[i]) dfs(i);
    for (int i = 'a'; i <= 'z'; i++) {if (!tt[i]) {d+=i;tt[i]=1;kl++;}}
    //cout << d << "\n";
    //cout << d.find('a') << " " << d.find('b') << "\n";
    if (d.size()!=26) {cout <<"NO\n";}
    for (int i = 0; i < s.size()-1; i++)
    {
        if (abs((ll)d.find(s[i])-(ll)d.find(s[i+1]))!=1)
        {
            cout << "NO\n";return;
        }
    }
    cout << "YES\n";
    cout << d << "\n";
    //cout << (ll)tt['x'-'a'] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
6 4
1 2
6 5
3 2
4 5
*/