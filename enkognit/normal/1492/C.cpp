#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, k, sf[3000001];
vector<ll> v[30];
string s, d;

void solve()
{
    cin >> n >> m;
    cin >> s;
    cin >> d;
    d=' '+d;
    for (int i = 0; i < s.size(); i++)
    {
        v[s[i]-'a'].pb(i+1);
    }
    ll o=m;
    s=' '+s;
    for (int i = n; i > 0; i--)
    {
        if (d[o]==s[i]) o--;
        sf[i]=m-o;
    }
    //cout << v[d[1]-'a'].size() << "\n";
    ll lst=v[d[1]-'a'][0], ans=0;
    for (int i = 2; i <= m; i++)
    {
        if (v[d[i]-'a'].size()==0)
        {
            break;
        }
        if (v[d[i]-'a'].back()<lst) break;
        ll l=0, r=v[d[i]-'a'].size()-1;
        while (l<r)
        {
            int w=(l+r+1)/2;
            if (sf[v[d[i]-'a'][w]+1]>=m-i) l=w; else r=w-1;
        }
        if (v[d[i]-'a'][l]<lst) break;
        ans=max(ans, v[d[i]-'a'][l]-lst);
        ll z=upper_bound(all(v[d[i]-'a']), lst)-v[d[i]-'a'].begin();
        if (z>=v[d[i]-'a'].size()) break;
        lst=v[d[i]-'a'][z];
    }
    cout << ans << "\n";
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
5
......
MMMC
......
CCCM
.X..X.
MMM
XXXXXX
CMMCM
......
MM

*/