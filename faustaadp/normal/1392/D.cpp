#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n;
char a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {   
        ll has = 0;
        vector<ll> isi;
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        ll hz = 0;
        for(ll i = 1; i <= n; i++)
        {
            hz++;
            if(i == n || a[i] != a[i + 1])
            {
                isi.pb(hz);
                hz = 0;
            }
        }
        ll sz = isi.size();
        if((sz > 1) && (sz % 2 == 1))
        {
            isi[0] += isi.back();
            isi.pop_back();
            sz--;
        }
        for(ll i = 0; i < sz; i++)
        {
            has += isi[i] / 3;
            // cout << i << " " << isi[i] << "\n";
        }
        if(sz == 1)
        {
            if(isi[0] < 3)
                has = 0;
            else
            if(isi[0] == 3)
                has = 1;
            else
            {
                has = isi[0] / 3 + ((isi[0] % 3) != 0);
            }
        }
        cout << has << "\n";
    }
}