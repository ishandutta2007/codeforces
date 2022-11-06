#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 2e5 + 5;
const int mo = 1e9 + 7;
ll n, a[NN], has;
vector<pair<ll, ll> > isi;
vector<ll> isi2;
ll x[NN];
ll d[NN];
ll nx[NN];
ll lst[NN];
ll m;
ll depe(ll pos)
{
    if(pos > m)
        return 0;
    if(d[pos] == -1)
    {
        d[pos] = depe(pos + 1);
        if(nx[pos - 1] != -1)
            d[pos] = max(d[pos], depe(nx[pos - 1]) + 1);
        // cout << pos << " " << d[pos] << "\n";
    }
    return d[pos];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    for(ll i = 1; i <= n; i++)
    {
        ll jum = 0, nx = n;
        for(ll j = i; j <= n; j++)
        {
            if(a[j] != a[i])
            {
                nx = j - 1; 
                break;
            }
            jum++;
        }
        x[++m] = a[i];
        i = nx;
    }
    for(ll i = 1; i <= m; i++)
        nx[i] = -1;
    for(ll i = 1; i <= m; i++)
    {
        if(lst[x[i]])
            nx[lst[x[i]]] = i;
        lst[x[i]] = i;
    }
    // for(ll i = 1; i <= m; i++)
        // cout << i << " " << nx[i] << "@\n";
    memset(d, -1, sizeof(d));
    cout << m - depe(2) << "\n";

}