#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, x[11], y[11], a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        ll has = 0;
        string s;
        cin >> s;
        ll n = s.length();
        for(ll i = 0; i < n; i++)
            a[i] = s[i] - '0';
        for(ll i = 0; i < 10; i++)
        {
            ll tmp = 0;
            for(ll j = 0; j < n; j++)
                tmp += (a[j] == i);
            has = max(has, tmp);
            for(ll j = 0; j < 10; j++)
                x[j] = 0;
            for(ll j = 0; j < 10; j++)
                y[j] = 0;
            for(ll j = 0; j < n; j++)
            {
                if(a[j] == i)
                {
                    for(ll k = 0; k < 10; k++)
                    {
                        y[k] += x[k];
                        x[k] = 0;
                    }
                }
                else
                    x[a[j]] = 1;
            }
            ll hz = 0;
            for(ll j = 0; j < 10; j++)
                hz = max(hz, y[j]);
            // cout << i << " " << hz << "\n";
            has = max(has, hz * 2LL);
        }
        cout << n - has << "\n";
    }
}