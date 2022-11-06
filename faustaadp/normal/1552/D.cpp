#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t;
ll n;
ll a[22];
ll ya;
void hai(ll pos, ll z)
{
    if(pos > n)
    {
        if(z == 0)
            ya++;
    }       
    else
    {
        hai(pos + 1, z);
        hai(pos + 1, z - a[pos]);
        hai(pos + 1, z + a[pos]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        ya = 0;
        hai(1, 0);
        if(ya > 1)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
}