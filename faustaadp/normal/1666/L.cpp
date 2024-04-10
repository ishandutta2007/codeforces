#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 5e5 + 5;
const ll mo = 998244353;
ll n, m, s;
vector<ll> v[NN];
ll p[NN];
ll jen[NN];
void jawab(ll now1, ll now2)
{
    // cout << now1 << "  " << now2 << "__\n";
    vector<ll> v1;
    vector<ll> v2;
    v1.pb(now2);
    while(now1 != s)
    {
        v1.pb(now1);
        now1 = p[now1];
    }
    while(now2 != s)
    {
        v2.pb(now2);
        now2 = p[now2];
    }
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    cout << "Possible\n";
    cout << v1.size() + 1 << "\n";
    cout << s;
    for(auto z : v1)
        cout << " " << z;
    cout << "\n";
    cout << v2.size() + 1 << "\n";
    cout << s;
    for(auto z : v2)
        cout << " " << z;
    cout << "\n";
    exit(0);
}
void dfs(ll pos, ll J)
{
    jen[pos] = J;
    for(auto nx : v[pos])
    {
        if(p[nx] == 0)
        {
            p[nx] = pos;
            // cout << nx << " " << p[nx] << "  " << J << "_\n";
            dfs(nx, J);
        }
        else
        if(jen[nx] != J && nx != s)
        {
            // cout << "hai\n";
            jawab(pos, nx);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> s;
    for(ll i = 1; i <= m; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        v[ta].pb(tb);
    }
    p[s] = s;
    ll JNS = 0;
    for(auto nx : v[s])
    {
        if(p[nx] == 0)
        {
            p[nx] = s;
            dfs(nx, ++JNS);
        }
        else
        {
            // cout << "HAI\n";
            jawab(s, nx);
        }
    }   
    cout << "Impossible\n";
}