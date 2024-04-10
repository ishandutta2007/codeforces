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
        string s;
        cin >> n;
        cin >> s;
        for(ll i = 0; i < n; i++)
        {
            if(s[i] == 'U')
                cout << "D";
            else
            if(s[i] == 'D')
                cout << "U";
            else
                cout << s[i];
        }
        cout << "\n";
    }
}