#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll a[NN];
pll A[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        ll sub = 0;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            A[i] = mp(a[i], i);
        }
        sort(A + 1, A + 1 + n);
        for(ll i = 1; i <= n; i++)
        {
            ll idx = A[i].se, nx = i;
            for(ll j = i + 1; j <= n; j++)
            {
                // cout << A[j].se << " " << idx << "@\n";
                if(A[j].se != idx + 1)
                    break;
                nx = j;
                idx = A[j].se;
            }
            // cout << i << " " << nx << "\n";
            i = nx;
            sub++;
        }
        // cout << sub << "\n";
        if(sub <= k)
            cout << "Yes\n";
        else
            cout << "No\n";
        // cout << sub << "\n";
    }
}