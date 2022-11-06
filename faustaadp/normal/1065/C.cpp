#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll n, k, has, h[NN], mi = 1e18;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(ll i = 1; i <= n; i++)
    {
        ll ta;
        cin >> ta;
        mi = min(mi, ta);
        h[ta]++;
    }
    ll hz = 0;
    for(ll i = 200000; i > mi; i--)
    {
        h[i] += h[i + 1];
        if(hz + h[i] > k)
        {
            hz = h[i];
            has++;
        }
        else
            hz += h[i];
    }
    has += (hz > 0);
    cout << has << "\n";
}