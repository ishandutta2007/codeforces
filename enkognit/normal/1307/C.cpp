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

ll n, m, T, k, kl, a[1000001];
vector<ll> v;
string s;
map<int,bool> ww;

void solve()
{
    cin >> s;
    vector<ll> v[28];
    ll ans=0;
    ll n=s.size();
    for (int i = 0 ;i < 26; i++) v[i].clear();
    for (int i = 0; i < n; i++)
    {
        v[s[i]-'a'].pb(i+1);
        ans=max(ans,(ll)v[s[i]-'a'].size());
    }
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 27; j++)
            if (v[i].size() && v[j].size())
        {
            if (i==j)
            {
                ans=max(ans,(ll)v[i].size()*((ll)v[i].size()-1)/2);
            }else
            {
                ll l=0, r=0;
                vector<pll> q;
                for (int u = 0; u < v[i].size(); u++) q.pb(mp(v[i][u],1));
                for (int u = 0; u < v[j].size(); u++) q.pb(mp(v[j][u],0));
                sort(q.begin(),q.end());
                ll o=0, y=0;
                for (int u = 0; u < q.size(); u++)
                {
                    if (q[u].se==0) o+=y; else y++;
                }
                //cout << o << " " << (char)(i+'a') << " " << (char)(j+'a') << "\n";
                //for (int u = 0; u < q.size(); u++) cout << q[u].fi << " ";
                //cout << "\n";
                ans=max(ans,o);
            }
        }
    cout << ans << "\n";
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
*/