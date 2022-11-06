#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 998244353;
const ll inf = (ll)1e18;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        string s;cin >> s;
        ll n = s.length();
        ll gagal = 0;
        ll hz = 0;
        if(s[n - 1] == 'A')
            gagal = 1;
        for(ll i = 0; i < n; i++)
        {
            if(s[i] == 'A')
                hz++;
            else
                hz--;
            if(hz < 0)
                gagal = 1;
        }
        if(gagal)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}