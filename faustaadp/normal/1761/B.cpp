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
        ll ada = 0, has = 0;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        if(n <= 2)
            has = n;
        else
        {
            a[n + 1] = a[1];
            a[n + 2] = a[2];
            for(ll i = 1; i <= n; i++)
                if(a[i] != a[i + 2])
                    ada = 1;
            if(ada)
                has = n;
            else
            {
                has = (n / 2) + 1;
            }
        }
        cout << has << "\n";
    }
}