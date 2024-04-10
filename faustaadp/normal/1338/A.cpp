#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll has, a[202020], t, n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        has = 0;
        ll ma = -1e18;
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            ma = max(ma, a[i]);
            has = max(has, ma - a[i]);
        }
        ll du = 1;
        if(has == 0)
            has = 0;
        else
        {         
            for(ll i = 1; i <= 60; i++)
            {
                if(has < du)
                {
                    has = i - 1;
                    break;
                }
                du *= 2;
            }
        }
        cout << has << "\n";
    }
}