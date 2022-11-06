#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, i, a[NN], d[1010101], L[1010101], R[1010101];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n;
    ll ma = 0;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(d[a[i]] == 0)
            L[a[i]] = i;
        R[a[i]] = i;
        d[a[i]]++;
        ma = max(ma, d[a[i]]);
    }
    ll j1 = 1, j2 = n;
    for(ll i = 1; i <= n; i++)
    {
        if(d[a[i]] == ma)
        {
            if((j2 - j1) > (R[a[i]] - L[a[i]]))
            {
                j1 = L[a[i]];
                j2 = R[a[i]];
            }
        }
    }
    cout << j1 << " " << j2 << "\n";
}