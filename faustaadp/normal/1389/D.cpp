#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, k, l1, l2, r1, r2;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cin >> l1 >> r1;
        cin >> l2 >> r2;
        ll L = min(l1, l2);
        ll R = max(r1, r2);
        ll pajak = 0;
        if(r1 < l2)
            pajak = l2 - r1;
        if(r2 < l1)
            pajak = l1 - r2;
        ll maxi = (R - L) * 2 - (r1 - l1) - (r2 - l2);
        ll awal = min(r1, r2) - max(l1, l2);
        awal = max(awal, 0LL);
        ll dapat = maxi - pajak;
        // cout << awal << " " << pajak << " " << dapat << " " << maxi << "\n";
        // cout << L << " " << R << " " << (r1 - l1) << " " << (r2 - l2) << "\n";
        ll has = 0, h2 = 1e18;
        for(ll i = 1; i <= n; i++)
            k -= awal;
        // cout << k << "_" << awal << "\n";
        for(ll i = 1; i <= n; i++)
        {
            if(k <= 0)
                break;
            if(k <= dapat)
            {
                has += pajak + k;
                k = 0;
                // cout << has << "\n";
                break;
            }
            k -= dapat;
            has += maxi;
            h2 = min(h2, has + k * 2LL);
            // cout << has << "_\n";
        }
        if(k > 0)
        {
            has += k * 2;
        }
        has = min(has, h2);
        cout << has << "\n";
    }
}