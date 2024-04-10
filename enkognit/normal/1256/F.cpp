#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define sqr(a) ((a)*(a))
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r;
ll q, y;
ll kla, klb, c[101], e[101];
ll a[1000001], f[300001];
string s, d;
vector <pll> v;
bool tt[1000001];

void update(ll h)
{
    for (int i = h; i <= 200000; i+=i&-i) f[i]++;
}

ll get(ll h)
{
    ll ans=0;
    for (int i = h; i > 0; i-=i&-i) ans+=f[i];
    return ans;
}

void solve()
{
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    for (int i = 0; i < 40; i++) c[i]=0, e[i]=0;
    for (int i = 0; i < n+15; i++) f[i]=0;
    for (int i = 0; i < n; i++) c[s[i]-'a']++, e[s[i]-'a']++, e[t[i]-'a']--;
    for (int i = 0; i < 40; i++) if (e[i]!=0) {cout << "NO\n";return;}
    for (int i = 0; i < 40; i++) if (c[i]>1) {cout << "YES\n";return;}
    vector <ll> v[40];
    for (int i = n-1; i > -1; i--) v[s[i]-'a'].pb(i);
    ll ans=0, k=0;
    for (int i = 0; i < n; i++)
    {
        ll p=k-get(v[t[i]-'a'][v[t[i]-'a'].size()-1]+1);
        if (v[t[i]-'a'][v[t[i]-'a'].size()-1]+p<i) continue;
        ans+=v[t[i]-'a'][v[t[i]-'a'].size()-1]-i+k-get(v[t[i]-'a'][v[t[i]-'a'].size()-1]+1);
        update(v[t[i]-'a'][v[t[i]-'a'].size()-1]+1);
        k++;
        v[t[i]-'a'].pop_back();
    }
    if (ans%2) cout << "NO\n"; else cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}