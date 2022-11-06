#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll t, n, a[NN];
pll A[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            A[i] = mp(a[i], i);
        }
        ll gagal = 0;
        sort(A + 1, A + 1 + n);
        for(ll i = 1; i <= n; i++)
        {
            ll kan = i;
            ll z[2];
            z[0] = 0;
            z[1] = 0;
            for(ll j = i; j <= n; j++)
            {
                if(A[j].fi != A[i].fi)break;
                z[j % 2]++;
                z[A[j].se % 2]--;
                kan = j;
            }
            if(z[0] != 0)gagal = 1;
            if(z[1] != 0)gagal = 1;
            i = kan;
        }
        if(gagal)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}