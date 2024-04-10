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

ll n, m, i, j, w, y, a[200001];
vector <pll> v, ans;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i];v.pb(mp(a[i],i*2-1));}
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (int i = 0; i < n-1; i++)
    {
        ans.pb(mp(v[i].se,v[i+1].se));
    }
    for (int i = 0; i < n; i++)
    {
        //cout << v[i].se+1 << "\n";
        ll r=v.size()-i-1;
        if (r>=v[i].fi-1)
        {
            ans.pb(mp(v[i+v[i].fi-1].se, v[i].se+1));
            if (i+v[i].fi-1==v.size()-1) v.pb(mp(0, v[i].se+1));
        }
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i].fi << " " << ans[i].se << "\n";
    return 0;
}