#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
const ll mo = 1e9 + 7;
ll t;
ll b[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll x, y;
        cin >> x >> y;
        if(x < y)
            swap(x, y);
        for(ll i = 0; i <= x + y; i++)
            b[i] = 0;
        ll t1 = (x + y) / 2;
        ll t2 = (x + y) - t1;
        ll R1 = min(x, t1) + min(y, t2);
        ll L1 = x + y - (min(y, t1) + min(x, t2));
        ll R2 = min(x, t2) + min(y, t1);
        ll L2 = x + y - (min(y, t2) + min(x, t1));
        for(ll i = L1; i <= R1; i+=2)
            b[i] = 1;
        for(ll i = L2; i <= R2; i+=2)
            b[i] = 1;
        vector<ll> jaw;
        for(ll i = 0; i <= x + y; i++)
            if(b[i])
                jaw.pb(i);
        cout << jaw.size() << "\n";
        for(auto z : jaw)
            cout << z << " ";
        cout << "\n";
    }
}