#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first

using namespace std;

ll n, m, k, l, r, i, j, a[1000001], d[10000001], ans[1000001];
bool tt[1000001];
vector <pll> v;
string s;

void solve()
{
    cin >> n >> m;
    cin >> s;
    string d="";
    for (int i = 1; i < m; i++) d+="()";
    for (int i = 0; i < n/2-m+1; i++) d+="(";
    for (int i = 0; i < n/2-m+1; i++) d+=")";
    //cout << d << "\n";
    vector <pll> v;
    for (int i = 0; i < s.size(); i++)
        if (s[i]!=d[i])
        {
            for (int j = i+1; j < s.size(); j++)
                if (s[j]==d[i]) {swap(s[i],s[j]);v.pb(mp(i+1, j+1));break;}
        }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i].fi << " " << v[i].se << "\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}