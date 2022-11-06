#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 4e5 + 5;
ll t, a[NN], b[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i <= m; i++)
            cin >> b[i];
        sort(a + 1, a + 1 + n);
        reverse(a + 1, a + 1 + n);
        ll has = 0;
        for(ll i = 1; i <= n; i++)
        {
            // cout << min(b[a[i]], b[i]) << "___\n";
            has += b[min(i, a[i])];
        }
        cout << has << "\n";
    }
}