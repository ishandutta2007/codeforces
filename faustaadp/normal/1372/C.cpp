#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, t;
ll a[NN], x[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll f = 0;
        ll urut = 1;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i <= n; i++)
            if(a[i] == i)
                x[i] = 1;
            else
            {
                urut = 0;
                x[i] = 0;
            }
        if(urut)
            cout << 0 << "\n";
        else
        {
            ll A = 0, B = 0;
            for(ll i = 1; i <= n; i++)
                if(x[i] == 0)
                {
                    A = i;
                    break;
                }
            for(ll i = 1; i <= n; i++)
                if(x[i] == 0)
                    B = i;
            ll jaw = 1;
            for(ll i = A; i <= B; i++)
                if(x[i] == 1)
                {
                    jaw = 2;
                    break;
                }
            cout << jaw << "\n";
        }
    }
}