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
    cin >> t;
    while(t--)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        ll n = s1.length();
        ll m = s2.length();
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        ll idx = 0;
        for(ll i = 0; i < n; i++)
        {
            if(idx == m)break;
            // cout << i << " " << 
            if(s1[i] == s2[idx])
            {
                idx++;
            }
            else
            {
                i++;
            }
        }
        if(idx == m)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}