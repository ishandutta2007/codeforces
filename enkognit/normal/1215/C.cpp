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

ll n, m, i, p, k, T, j, y, kol, tt[1000001];
string s, t;
vector <pair<pair<char,char>,ll> > u, z;
ll c[1001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    cin >> t;
    for (int i = 0; i < n; i++) c[s[i]-'a']++;
    for (int i = 0; i < n; i++) c[t[i]-'a']++;
    for (int i = 'a'; i <= 'z'; i++) if (c[i-'a']%2) {cout << "-1";exit(0);}
    for (int i = 0; i < n; i++)
    {
        if (s[i]!=t[i]) u.pb(mp(mp(s[i],t[i]), i+1));
    }
    if (u.size()==0) {cout << 0;exit(0);}
    sort(u.begin(),u.end());
    vector <pll> ans;
    for (int i = 0; i < u.size()-1; i++)
    {
        if (u[i].fi.fi==u[i+1].fi.fi)
        {ans.pb(mp(u[i].se,u[i+1].se));tt[i]=1,tt[i+1]=1;i++;}
    }
    ll l=0;
    z=u;
    u.clear();
    for (int i = 0; i < z.size(); i++) if (!tt[i]) u.pb(z[i]);
    for (int i = 0; i < u.size(); i++)
    {
        if (u[i].fi.fi=='a') l++;
    }
    if (l<u.size()/2)
    {
        for (int i = 0; i < u.size(); i++)
        {
            if (u[i].fi.fi=='a') {swap(u[i].fi.fi,u[i].fi.se);ans.pb(mp(u[i].se,u[i].se));}
        }
    }else
    for (int i = 0; i < u.size(); i++)
        {
            if (u[i].fi.fi=='b') swap(u[i].fi.fi,u[i].fi.se),ans.pb(mp(u[i].se,u[i].se));;
        }
    if (u.size())
    for (int i = 0; i < u.size()/2; i++)
        ans.pb(mp(u[i].se,u[u.size()-1-i].se));
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i].fi << " " << ans[i].se << "\n";
    return 0;
}