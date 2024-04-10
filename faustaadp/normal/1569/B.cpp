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
ll x[555][555];
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
        vector<ll> isi;
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < n; j++)
                x[i][j] = 0;
        for(ll i = 0; i < n; i++)
            if(s[i] == '2')
                isi.pb(i);
        if(isi.size() == 1 || isi.size() == 2)
            cout << "NO\n";
        else
        {
            ll sz = isi.size();
            for(ll i = 0; i < sz; i++)
            {
                x[isi[i]][isi[(i + 1) % sz]] = 1;
                x[isi[(i + 1) % sz]][isi[i]] = -1;
            }
            cout << "YES\n";    
            for(ll i = 0; i < n; i++)
            {
                for(ll j = 0; j < n; j++)
                {
                    if(i == j)
                        cout << "X";
                    else
                    if(x[i][j] == 0)
                        cout << "=";
                    else
                    if(x[i][j] == 1)
                        cout << "+";
                    else
                        cout << "-";
                }
                cout << "\n";
            }
        }
    }
}