#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 1e9 + 7;
const ll inf = (ll)1e18 + 1;
ll t, cnt[999];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        for(ll i = 0; i <= 100; i++)
            cnt[i] = 0;
        for(ll i = 1; i <= n; i++)
        {
            ll ta;
            cin >> ta;
            ll z = abs(ta);
            cnt[z]++;
        }
        ll has = 0;
        if(cnt[0] > 0)
            has = 1;
        for(ll i = 1; i <= 100; i++)
            has += min(2LL, cnt[i]);
        cout << has << "\n";
    }
}