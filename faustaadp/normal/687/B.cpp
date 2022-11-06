#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 1e4 + 5;
ll n, k;
ll pr[1010101], x[1010101], y[1010101];
vector<ll> p, isi;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    for(ll i = 2; i <= 1000000; i++)
        if(!pr[i])
        {
            p.pb(i);
            for(ll j = i * i; j <= 1000000; j += i)
                pr[j] = 1;
        }
    cin >> n >> k;
    for(ll i = 0; i < p.size(); i++)
        if(k % p[i] == 0)
        {
            isi.pb(p[i]);
            while(k % p[i] == 0)
            {
                x[p[i]]++;
                k /= p[i];
            }
        }
    for(ll i = 1; i <= n; i++)
    {
        ll ta;
        cin >> ta;
        for(ll j = 0; j < isi.size(); j++)
        {
            ll hz = 0;
            while(ta % isi[j] == 0)
            {
                hz++;
                ta /= isi[j];
            }
            y[isi[j]] = max(y[isi[j]], hz);
        }
    }
    for(ll i = 0; i < isi.size(); i++)
        if(x[isi[i]] > y[isi[i]])
        {
            cout << "No\n";
            return 0;
        }
    cout << "Yes\n";
}