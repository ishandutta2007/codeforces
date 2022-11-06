#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll n, a[NN], IN[NN], OUT[NN], te;
map<ll, ll> me, me2;
ll dep[NN];
ll pp[22][NN];
vector<ll> v[NN], z[NN], za[NN];
ll p[NN], x[NN];
void dfs1(ll pos, ll par, ll dpt)
{
    dep[pos] = dpt;
    IN[pos] = ++te;
    pp[0][pos] = par;
    for(ll i = 1; i <= 20; i++)
        pp[i][pos] = pp[i - 1][pp[i - 1][pos]];
    for(ll i = 0; i < v[pos].size(); i++)
        if(v[pos][i] != par)
            dfs1(v[pos][i], pos, dpt + 1);
    OUT[pos] = te;
}
ll cari(ll pos, ll tig)
{
    for(ll i = 20; i >= 0; i--)
    {
        if(tig >= (1 << i))
        {
            pos = pp[i][pos];
            tig -= (1 << i);
        }
    }
    return pos;
}
void dfs(ll pos, ll par)
{
    z[a[pos]].pb(pos);
    // cout << a[pos] << " " << z[a[pos]].size() << "\n";
    if(z[a[pos]].size() == 3)
    {
        cout << 0 << "\n";
        exit(0);
    }
    if(z[a[pos]].size() == 2)
    {
        p[IN[z[a[pos]][0]]]++;
        p[IN[z[a[pos]][0]] + 1]--;

        ll N = cari(pos, dep[pos] - dep[z[a[pos]][0]] - 1);
        // cout << N << "\n";
        p[1]++;
        p[IN[N]]--;

        p[OUT[N] + 1]++;

        p[IN[pos]]++;
        p[OUT[pos] + 1]--; 
        // x[z[a[pos]][0]] = 0;
        // cout << IN[pos] << "  " << OUT[pos] << "\n";
        // cout << 1 << "  " << IN[z[a[pos]][0]] << "\n";
        // cout << OUT[z[a[pos]][0]] + 1 << "  " << n << "\n";
    }
    if(z[a[pos]].size() == 1)
        za[a[pos]].pb(z[a[pos]][0]); 
    for(ll i = 0; i < v[pos].size(); i++)
        if(v[pos][i] != par)
            dfs(v[pos][i], pos);
    // if(x[pos])
    // {
    //     cout << IN[pos] << "  " << OUT[pos] << "\n";
    //     p[IN[pos]]++;
    //     p[OUT[pos] + 1]--; 
    // }
    z[a[pos]].pop_back();
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    vector<ll> isi;
    for(ll i = 1; i <= n; i++)
        isi.pb(a[i]);
    sort(isi.begin(), isi.end());
    for(ll i = 0; i < n; i++)
    {
        me[isi[i]] = i;
        me2[isi[i]]++;
    }
    for(ll i = 1; i <= n; i++)
    {
        if(me2[a[i]] > 1)
            x[i] = 1;
        a[i] = me[a[i]];
    }
    for(ll i = 1; i < n; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        v[ta].pb(tb);
        v[tb].pb(ta);
    }
    dfs1(1, 1, 0);
    // return 0;
    dfs(1, 1);
    for(ll i = 1; i <= n; i++)
    {
        // cout << i << "  " << a[i] << "\n";
        if(!x[i])continue;
        if(za[a[i]].size() == 1 && za[a[i]][0] == i)continue;
        // cout << i << "\n";
        // cout << IN[i] << "  " << OUT[i] << "\n";
        p[IN[i]]++;
        p[OUT[i] + 1]--;
    }
    // return 0;
    ll hz = 0, has = 0;
    for(ll i = 1; i <= n; i++)
    {
        hz += p[i];
        // cout << i << " " << hz << "\n";
        if(hz == 0)
            has++;
    }
    cout << has << "\n";
}