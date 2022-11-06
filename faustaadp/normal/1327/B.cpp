#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t, n;
ll b[202020];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
            b[i] = 0;
        ll kiri = -1, kanan = -1;
        for(ll i = 1; i <= n; i++)
        {
            ll ta, udh = 0;
            cin >> ta;
            while(ta--)
            {
                ll tb;
                cin >> tb;
                if((udh == 0) && (b[tb] == 0))
                {
                    // cout << i << " " << tb << "\n";
                    udh = 1;
                    b[tb] = 1;
                }
            }
            if(udh == 0)
                kiri = i;
        }
        for(ll i = 1; i <= n; i++)
            if(b[i] == 0)
                kanan = i;
        if(kiri == -1)
            cout << "OPTIMAL\n";
        else
        {
            cout << "IMPROVE\n";
            cout << kiri << " " << kanan << "\n"; 
        }
    }
}