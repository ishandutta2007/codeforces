#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, m, i, j, k, l, r, a[500001];
pll b[500001];
string s, d;
vector <ll> v;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    ll k=1;
    for (int i = 0; i < s.size(); i++) k*=(s[i]-48);
    ll ans=k, p=1;
    if (s[0]-48==1) ans=max(ans,(ll)pow(9,s.size()-1));
    for (int i = 0; i < s.size(); i++) if (s[i]>48)ans=max(ans,(ll)(p*(s[i]-49)*pow(9,(ll)s.size()-1-i))),p*=(s[i]-48);
    cout << ans;
    return 0;
}