#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll t, n, m, has;
ll a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        has = 0;
        ll ada = 0;
        ll mx = 0;
        for(ll i = 1;i <= n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
            if(a[i] == m)
                ada = 1;
        }
        has = m / mx + ((m % mx) != 0);
        if(ada)
            has = max(has, 1LL);
        else
            has = max(has, 2LL);
        cout << has << "\n";
    }
}