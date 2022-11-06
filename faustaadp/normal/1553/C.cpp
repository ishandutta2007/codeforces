#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t;
string s2;
ll z[2020];
ll has;
void hai(ll pos, ll hz)
{
    if(pos == 10)
    {
        // cout << hz << "\n"; 
        has = min(has, z[hz]);
    }
    else
    {
        if(s2[pos] == '1')
            hai(pos + 1, hz + (1 << pos));
        else
        if(s2[pos] == '0')
            hai(pos + 1, hz);
        else
        {
            hai(pos + 1, hz + (1 << pos));
            hai(pos + 1, hz);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(ll i = 0; i < 1024; i++)
    {
        ll h[2];
        ll s[2];
        h[0] = 0;
        h[1] = 0;
        s[0] = 5;
        s[1] = 5;
        z[i] = 10;
        for(ll j = 0; j < 10; j++)
        {
            s[j % 2]--;
            if(i & (1 << j))
                h[j % 2]++;
            if(h[0] + s[0] < h[1])
            {
                z[i] = j + 1;
                break;
            }
            if(h[1] + s[1] < h[0])
            {
                z[i] = j + 1;
                break;
            }
        }
    }
    cin >> t;
    while(t--)
    {
        has = 1e18;
        cin >> s2;
        hai(0, 0);
        cout << has << "\n";
    }
}