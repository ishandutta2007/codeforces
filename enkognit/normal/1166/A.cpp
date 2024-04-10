#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, l, r, ans, k, a[500003];
string s, d;
vector <char> v;
map<char,ll> t;

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        t[s[0]]++;
        if (t[s[0]]==1) v.pb(s[0]);
    }
    for (int i = 0; i < v.size(); i++)
    {
        ll l=t[v[i]]/2, r=t[v[i]]-l;
        //cout << l*(l-1) << " " << r*(r-1) << "\n";
        ans+=l*(l-1)+r*(r-1);
    }
    cout << ans/2;
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4
bokutachi wa benkyou ga dekinai
*/