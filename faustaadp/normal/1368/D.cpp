#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t, x[99], n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        ll ta;
        cin >> ta;
        for(ll j = 0; j < 20; j++)
            if(ta & (1 << j))
                x[j]++;
    }
    ll has = 0;
    for(ll i = 1; i <= n; i++)
    {
        ll hz = 0;
        for(ll j = 0; j < 20; j++)
            if(x[j] >= i)
                hz += (1 << j);
        has += hz * hz;
    }
    cout << has << "\n";
}