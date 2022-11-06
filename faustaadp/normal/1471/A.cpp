#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 4e5 + 5;
ll t, a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll n, x;
        cin >> n >> x;
        ll sum = 0, h1 = 0;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
            h1 += (a[i] + x - 1) / x;
        }
        sum = (sum + x - 1) / x;
        cout << sum << " " << h1 << "\n";
    }
}