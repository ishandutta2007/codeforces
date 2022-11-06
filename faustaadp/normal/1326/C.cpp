#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n, k, mo = 998244353;
vector<ll> v; 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    ll bwh = n - k + 1;
    ll h1 = 0, h2 = 1;
    for(ll i = 1; i <= n; i++)
    {
        ll ta;
        cin >> ta;
        if(ta >= bwh)
        {
            h1 += ta;
            v.pb(i);
        }
    }
    ll sz = v.size();
    for(ll i = 1; i < sz; i++)
    {
        // cout << v[i] - v[i - 1] << "__\n"; 
        h2 = (h2 * (v[i] - v[i - 1])) % mo;
    }
    cout << h1 << " " << h2 << "\n";
}