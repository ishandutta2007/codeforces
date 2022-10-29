#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;

ll n, T, kl = 0, m, c[1000001];
string s;

void solve()
{
    cin >> n;
    cin >> s;
    string d = s;
   // cout << d << "\n";
    vector <pair<string,int> > v;
    for (int i = n - 1; i > -1; i--)
    {
        d.pop_back();
        if ((n - i) % 2 && d.size()) reverse(all(d));
        //cout << i << "\n";
        v.pb(mp(s.substr(i,n-i)+d, i+1));
        if ((n - i) % 2 && d.size()) reverse(all(d));
    }
    sort(all(v));
    cout << v[0].first << "\n" << v[0].second << "\n";
}

int main()
{
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
6
add 1
sum 1 1
add 3
add 1
sum 2 3
sum 1 2
*/