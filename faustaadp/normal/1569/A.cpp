#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll idx = -1;
        for(ll i = 1; i < n; i++)
            if(s[i - 1] != s[i])
                idx = i + 1;
        if(idx == -1)
            cout << -1 << " " << -1 << "\n";
        else
            cout << idx - 1 << " " << idx << "\n";
    }
}