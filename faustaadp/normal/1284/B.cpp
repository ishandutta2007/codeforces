#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e5 + 5;
ll n, m, i, mi[NN], ma[NN], a[NN], b[NN], has, tam;
ll x[1010101];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> m;
        mi[i] = 1e18;
        ma[i] = -1e18;
        b[i] = 1;
        for(ll j = 1; j <= m; j++)
            cin >> a[j];
        for(ll j = 1; j <= m; j++)
        {
            mi[i] = min(mi[i], a[j]);
            ma[i] = max(ma[i], a[j]);
        }
        for(ll j = 1; j < m; j++)
            if(a[j] < a[j + 1])
                b[i] = 0;
        if(b[i])
            x[mi[i]]++;
        else
            tam++;
    }
    for(ll i = 1; i <= 1000000; i++)
        x[i] += x[i - 1];
    ll las = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(b[i] == 0)
        {
            // cout << i << "_\n";
            has += n;
        }
        else
        {
            has += x[ma[i] - 1] + tam;
        }
        // cout << i << " " <<has - las << "\n";
        las = has;
    }
    cout << has << "\n";

}