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
ll n, k, te;
map<ll, ll> me;
vector<ll> v[NN];
ll d[NN][7];
ll warna[NN];
ll powo(ll A, ll B)
{
    if(B == 0)
        return 1;
    else
    {
        ll ret = powo(A, B / 2);
        ret = (ret * ret) % mo;
        if(B % 2 == 1)
            ret = (ret * A) % mo;
        return ret;
    }
}
ll nama(ll pos, ll z)
{
    if(me[pos] == 0)
    {
        me[pos] = ++te;
        warna[me[pos]] = z;
    }
    warna[me[pos]] = min(warna[me[pos]], z);
    return me[pos];
}
ll depe(ll pos, ll lst)
{
    ll &ret = d[pos][lst];
    if(ret == -1)
    {
        ret = 0;
        sort(v[pos].begin(), v[pos].end());
        for(ll i = 0; i < 6; i++)
        {
            if(warna[pos] != 6 && warna[pos] != i)
                continue;
            if(lst == 6 || abs(lst - i) % 3 != 0)
            {
                ll hz = 1;
                for(ll j = 0; j < v[pos].size(); j++)
                {
                    if(j > 0 && v[pos][j] == v[pos][j - 1])
                        continue;
                    hz = (hz * depe(v[pos][j], i)) % mo;
                }
                ret = (ret + hz) % mo;
            }
        }
        // cout << pos << " " << lst << " " << ret << "\n";
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> k;
    cin >> n;
    map<string, ll> con;
    con["white"] = 0;
    con["yellow"] = 3;
    con["red"] = 1;
    con["orange"] = 4;
    con["blue"] = 2;
    con["green"] = 5;
    nama(1, 6);
    for(ll i = 1; i <= n; i++)
    {
        ll nd;
        string war;
        cin >> nd >> war;
        ll id_war = con[war];
        nama(nd, id_war);
        while(nd > 1)
        {
            v[nama(nd / 2, 6)].pb(nama(nd, 6));
            nd /= 2;
        }
    }
    ll banyak = (1LL << k) - 1LL;
    ll sisa = banyak - te;
    ll has = powo(4LL, sisa) % mo;
    memset(d, -1, sizeof(d));
    has = (has * depe(1, 6)) % mo;
    cout << has << "\n";
}