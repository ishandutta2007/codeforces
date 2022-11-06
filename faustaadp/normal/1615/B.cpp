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
ll p[33][200005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(ll i = 0; i <= 30; i++)
        for(ll j = 1; j <= 200000; j++) 
        {
            p[i][j] = p[i][j - 1];
            if(j & (1 << i))
                p[i][j]++;
            // p[i][j] = p[i][j - 1];
        }
    ll t;
    cin >> t;
    while(t--)
    {
        ll ta, tb;
        cin >> ta >> tb;
        ll has = 1e18;
        for(ll i = 0; i <= 30; i++)
        {
            // cout << ta << " " << tb << "  " << p[i][tb] - p[i][ta - 1] << "  "  << (tb - ta + 1) - p[i][tb] - p[i][ta - 1] << "__\n";
            has = min(has, (tb - ta + 1) - p[i][tb] + p[i][ta - 1]);
        }
        cout << has << "\n";
    }
}