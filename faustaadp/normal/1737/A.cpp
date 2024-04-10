#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
ll cnt[999];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        for(ll i = 0; i < 26; i++)
            cnt[i] = 0;
        ll n, k;
        cin >> n >> k;
        for(ll i = 0; i < n; i++)
        {
            char ct;
            cin >> ct;
            cnt[ct - 'a']++;
        }
        for(ll i = 0; i < k; i++)
        {
            for(ll j = 0; j <= n / k; j++)
            {
                if(cnt[j] && j < (n / k))
                    cnt[j]--;
                else
                {
                    cout << char(j + 'a');
                    break;
                }
            }
        }
        cout << "\n";
    }
}