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
ll t;
char c[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll udh = 0;
        string s;
        for(ll i = 1; i <= n; i++)
            cin >> c[i];
        for(ll i = 1; i <= n; i++)
        {
            if(i == 1)
                s += c[i];
            else
            if(i == 2 && c[i] < c[i - 1])
                s += c[i];
            else
            if(i > 2 && c[i] <= c[i - 1])
                s += c[i];
            else
                break;
        }
        cout << s;
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
}