#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll n, m;
vector<pll> isi[NN];
set<pair<pll, ll> > st;
ll d[NN];
ll b[NN];
vector<ll> v[NN];
ll depe(ll pos)
{
    ll &ret = d[pos];
    if(ret == -1)
    {
        ret = 1;
        for(ll i = 0; i < v[pos].size(); i++)
            ret = max(ret, depe(v[pos][i]) + 1);
    }
    return ret;
}
void bt(ll pos)
{
    b[pos] = 1;
    for(ll i = 0; i < v[pos].size(); i++)
        if(depe(pos) == depe(v[pos][i]) + 1)
        {
            bt(v[pos][i]);
            return ;
        }
        // ret = max(ret, depe(v[pos][i]));
}
void cetak()
{
    cout << "begin\n";
    for(auto z : st)
    {
        cout << z.fi.fi << " " << z.fi.se << "  " << z.se << "\n";
    }
    cout << "end\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    ll inf = 1e18;
    for(ll i = 1; i <= m; i++)
    {
        ll ta, tb, tc;
        cin >> ta >> tb >> tc;
        isi[ta].pb(mp(tb, tc));
    }
    st.insert(mp(mp(-1, -1), -1));
    st.insert(mp(mp(inf, inf), -1));
    for(ll i = 1; i <= n; i++)
    {
        sort(isi[i].begin(), isi[i].end());
        ll lst = 0;
        for(ll j = 0; j < isi[i].size(); j++)
        {
            vector<pair<pll, ll> > tam;
            vector<pair<pll, ll> > hap;
            ll L = max(lst + 1, isi[i][j].fi);
            ll R = isi[i][j].se;
            lst = max(lst, R);
            if(L > R)continue;
            auto it1 = st.lower_bound(mp(mp(L, -inf), 0));
            it1--;
            auto it2 = st.lower_bound(mp(mp(R, inf), 0));
            it2--;
            tam.pb(mp(mp(L, R), i));
            if(((*it2).se) != -1 && ((*it2).fi.se > R))
            {
                // hap.pb(*it2);
                tam.pb(mp(mp(R + 1, (*it2).fi.se), (*it2).se));
            }
            if(((*it1).se) != -1 && ((*it1).fi.se >= L))
            {
                hap.pb(*it1);
                tam.pb(mp(mp((*it1).fi.fi, L - 1), (*it1).se));
            }
            if(it1 != it2)
            {      
                // it1++;   
                while(1)
                {
                    it1++;
                    hap.pb(*it1);
                    if(it1 == it2)break;   
                }
            }
            for(ll k = 0; k < hap.size(); k++)
            {
                v[hap[k].se].pb(i);
                // cout << hap[k].se << " -> " << i << "\n";
                st.erase(hap[k]);
            }
            for(ll k = 0; k < tam.size(); k++)
                st.insert(tam[k]);
        }
        // cetak();
    }
    memset(d, -1, sizeof(d));
    ll ma = 0;
    for(ll i = 1; i <= n; i++)
        ma = max(ma, depe(i));
    for(ll i = 1; i <= n; i++)
    {
        if(ma == depe(i))
        {
            bt(i);
            break;
        }
    }
    // cout << depe(1) << "_\n";
    // bt(1);
    vector<ll> jaw;
    for(ll i = 1; i <= n; i++)
        if(!b[i])
            jaw.pb(i);
    cout << jaw.size() << "\n";
    for(auto z : jaw)
        cout << z << " ";
    cout << "\n";
}