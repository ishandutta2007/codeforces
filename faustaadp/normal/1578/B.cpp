#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll n;
vector<ll> v[NN];
vector<ll> isi;
ll p[NN];
void dfs(ll pos, ll par)
{
    p[pos] = par;
    if(pos != par)
        isi.pb(pos);
    for(auto nx : v[pos])
        if(nx != par)
            dfs(nx, pos);
}
vector<ll> kompres(vector<ll> z)
{
    ll b[n + 1];
    memset(b, 0, sizeof(b));
    for(auto zz : z)
        b[zz] = 1, b[p[zz]] = 1;
    vector<ll> ret;
    for(ll i = 1; i <= n; i++)
        if(b[i])
            ret.pb(i);
    return ret;
}
ll tanya(vector<ll> z)
{
    cout << "? " << z.size();
    for(auto zz : z)
        cout << " " << zz;
    cout << endl;
    ll ret;
    cin >> ret;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n;
    for(ll i = 1; i < n; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        v[ta].pb(tb);
        v[tb].pb(ta);
    }
    dfs(1, 1);
    ll B = tanya(kompres(isi));
    // cout << B << "\n";
    while(isi.size() > 1)
    {
        ll sz = isi.size();
        vector<ll> cal1;
        vector<ll> cal2;
        for(ll i = 0; i < sz / 2; i++)
            cal1.pb(isi[i]);
        for(ll i = sz / 2; i < sz; i++)
            cal2.pb(isi[i]);
        ll jawaban = tanya(kompres(cal1));
        if(jawaban == B)
            isi = cal1;
        else
            isi = cal2;
    }
    cout << "! " << isi[0] << " " << p[isi[0]] << endl;
}