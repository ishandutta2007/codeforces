#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define pld pair<ld,ld>
#define OO 1000000000000000000

using namespace std;

ll n, kl, m, k, i, j, h, a[1000001];
string s[100001];
bool tt[1000001];
map<string,vector<ll> > w;
vector<string> v, z;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        string d=s[i];
        reverse(all(d));
        if (w[d].size()) {tt[w[d].back()]=0;w[d].pop_back();v.pb(s[i]);z.pb(d);} else
        {
            w[s[i]].pb(i);
            tt[i]=1;
        }
    }
    string ans="";
    for (int i = 0; i < v.size(); i++)
    {
        ans+=v[i];
    }
    for (int i = 1; i <= n; i++)
        if (tt[i])
    {
        bool t=1;
        for (int j = 0; j < m/2; j++)
            if (s[i][j]!=s[i][m-j-1]) {t=0;break;}
        if (t) {ans+=s[i];break;}
    }
    for (int i = z.size()-1; i > -1; i--)
    {
        ans+=z[i];
    }
    cout << ans.size() << "\n";
    cout << ans << "\n";
    return 0;
}
/*
*/