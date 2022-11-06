#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll t, n, k;
char a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        vector<ll> isi;
        cin >> n >> k;
        ll L = 0;
        ll W = 0;
        ll has = 0;
        ll hz = 0;
        a[0] = 'L';
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(W > 0 && a[i] == 'L')
            {
                hz++;
            }
            if(a[i] == 'W' && hz > 0)
            {
                // cout << hz << "\n";
                isi.pb(hz);
                hz = 0;
            }
            if(a[i] == 'W')W++;
            if(a[i] == 'L')L++;
            if(a[i] == 'W')has++;
            if(a[i] == 'W' && a[i - 1] == 'W')has++;
        }
        if(W == 0)
            has = k * 2 - 1;
        else
        {
            k = min(k, L);
            sort(isi.begin(), isi.end());
            reverse(isi.begin(), isi.end());
            has += k * 2;
            // cout << has << "\n";
            while(1)
            {
                if(isi.empty())break;
                k -= isi.back();
                isi.pop_back();
                if(k < 0)
                    break;
                has++;
            }
        }
        has = max(has, 0LL);
        cout << has << "\n";
    }
}