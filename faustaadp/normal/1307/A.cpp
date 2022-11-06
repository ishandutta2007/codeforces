#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll t, n, m, i, has;
ll a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        has = 0;
        cin >> n >> m;
        for(ll i = 1;i <= n; i++)
            cin >> a[i];
        for(ll i = 1;i <= n; i++)
        {
            while((m >= (i - 1)) && (a[i] > 0))
            {
                has++;
                a[i]--;
                m -= (i - 1);
            }
        }
        cout << has << "\n";

    }
}