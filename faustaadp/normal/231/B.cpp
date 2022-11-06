#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, d, l, a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> d >> l;
    // ll ma, mi;
    // if(n % 2 == 0)
    // {
    //     mi = (n / 2) - (n / 2) * l;
    //     ma = (n / 2) * l - (n / 2);
    // }
    // else
    // {
    //     mi = (n / 2 + 1) - (n / 2) * l;
    //     ma = (n / 2 + 1) * l - (n / 2 + 1);   
    // }
    // if(mi <= d && d <= ma)
    // {
        if(n % 2 == 1)
            d--;
        for(ll i = 1; i <= n; i++)
            a[i] = 1;
        for(ll i = 1; i <= n; i++)
        {
            if(i % 2 == 1)
            {
                if(d > 0)
                {
                    ll hey = min(l - 1, d);
                    a[i] += hey;
                    d -= hey;
                }
            }
            else
            {
                if(d < 0)
                {
                    ll hey = min(l - 1, -d);
                    a[i] += hey;
                    d += hey;
                }
            }
        }
        if(d != 0)
        {
            cout << -1 << "\n";
        }
        else
        { 
            for(ll i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
        }
    // }
    // else
        // cout << -1 << "\n";
}