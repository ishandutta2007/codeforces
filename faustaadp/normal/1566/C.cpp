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
ll a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        string s1, s2;
        cin >> s1;
        cin >> s2;
        for(ll i = 0; i < n; i++)
        {
            if(s1[i] != s2[i])
                a[i] = 2;
            else
            if(s1[i] == '0')
                a[i] = 1;
            else
                a[i] = 0;
        }
        ll has = 0;
        for(ll i = 0; i < n; i++)
        {
            if(a[i] == 2)
                has += 2;
            else
            {
                if(i + 1 < n && a[i] + a[i + 1] == 1)
                {
                    has += 2;
                    i++;
                }
                else
                    has += a[i];
            }
            // cout << i << " " << has << "\n";
        }
        cout << has << "\n";
    }
}