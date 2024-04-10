#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e5 + 5;
ll mo = 1e9 + 7;
ll n, i, a1[NN], a2[NN], b1[NN], b2[NN];
map<ll,ll> me;
ll x[4*NN];
ll x2[4*NN];
ll y[4*NN];
ll y2[4*NN];
ll a[NN];
ll z[NN][5];
vector<ll> isi;
void masuk(ll aa)
{
    isi.pb(aa);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a1[i] >> a2[i];
        cin >> b1[i] >> b2[i];
        masuk(a1[i]);
        masuk(a2[i]);
        masuk(b1[i]);
        masuk(b2[i]);
    }
    sort(isi.begin(), isi.end());
    for(ll i = 0; i < isi.size(); i++)
        me[isi[i]] = i + 1;
    srand(time(NULL));
    ll julian = rand() % 1000000007;
    // julian = 0;
    for(ll i = 1; i <= n; i++)
    {
        a1[i] = me[a1[i]];
        a2[i] = me[a2[i]];
        b1[i] = me[b1[i]];
        b2[i] = me[b2[i]];
    }
    for(ll i = 1; i <= n; i++)
    {
        x[a1[i]]++;
        x2[a1[i]]+=(i ^ julian);
        y[a2[i]]++;
        y2[a2[i]]+=(i ^ julian);
        x2[a1[i]] %= mo;
        y2[a2[i]] %= mo;
    }
    for(ll i = 1; i <= n*4 ; i++)
    {
        y[i] += y[i - 1];
        y2[i] = (y2[i - 1] + y2[i]) % mo;
        // cout << i << "_" << y2[i] << "\n";
    }
    for(ll i = n*4; i >= 1 ; i--)
    {
        x[i] += x[i + 1]; 
        x2[i] = (x2[i + 1] + x2[i]) % mo;
        // cout << i << "_" << x2[i] << "\n";
    }
    for(ll i = 1; i <= n; i++)
    {
        // cout << a1[i] << " " << a2[i] << "WA_\n";
        z[i][0] = x[a2[i] + 1]; 
        z[i][1] = x2[a2[i] + 1]; 
        z[i][0] += y[a1[i] - 1]; 
        z[i][1] += y2[a1[i] - 1]; 
        z[i][1] %= mo;
    }
    for(ll i = 1; i <= n; i++)
    {
        a1[i] = b1[i];
        a2[i] = b2[i];
    }
    memset(x, 0, sizeof(x));
    memset(x2, 0, sizeof(x2));
    memset(y, 0, sizeof(y));
    memset(y2, 0, sizeof(y2));
    for(ll i = 1; i <= n; i++)
    {
        x[a1[i]]++;
        x2[a1[i]]+=(i ^ julian);
        y[a2[i]]++;
        y2[a2[i]]+=(i ^ julian);
        x2[a1[i]] %= mo;
        y2[a2[i]] %= mo;
    }
    for(ll i = 1; i <= n*4 ; i++)
    {
        y[i] += y[i - 1];
        y2[i] = (y2[i - 1] + y2[i]) % mo;
    }
    for(ll i = n*4; i >= 1 ; i--)
    {
        x[i] += x[i + 1];
        x2[i] = (x2[i + 1] + x2[i]) % mo;
    }
    for(ll i = 1; i <= n; i++)
    {
        a[0] = x[a2[i] + 1]; 
        a[1] = x2[a2[i] + 1]; 
        a[0] += y[a1[i] - 1]; 
        a[1] += y2[a1[i] - 1]; 
        // cout << i << "AAA" << a[1] << "\n";
        // cout << i << "AAA" << z[1] << "\n";
        // a[1] %= mo;
        // cout << i << ":\n";
        // cout << a[0] << " " << z[i][0] << "_\n";
        // cout << a[1] << " " << z[i][1] << "_\n";
        if(a[0] != z[i][0])
        {
            cout << "NO\n";
            return 0;
        }
        // if(a[1] != z[i][1])
        // {
        //     cout << "NO\n";
        //     return 0;
        // }
    }
    cout << "YES\n";
}