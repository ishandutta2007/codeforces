#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
const ll mo = 998244353;
const ll inf = (ll)1e18;
ll n, m;
ll jum1[NN], jum2[NN], ada[NN], p[NN];
ll a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        string s;
        cin >> s;
        for(ll i = 0; i < n * m; i++)
            a[i] = (s[i] == '1');
        for(ll i = 0; i < n * m; i++)
            p[i + 1] = p[i] + a[i];
        for(ll i = 0; i < m; i++)
            ada[i] = 0;
        ll tmp = 0;
        for(ll i = 0; i < n * m; i++)
        {
            if(a[i])
            {
                if(ada[i % m] == 0)
                {
                    ada[i % m] = 1;
                    tmp++;
                }
            }
            jum1[i] = tmp;
        }
        for(ll i = 1; i <= m; i++)
        {
            for(ll j = i; j <= n * m; j += i)
            {
                jum2[j - 1] = 0;
                if(j - m >= 1)
                    jum2[j - 1] = jum2[j - m - 1];
                if((p[j] - p[max(j - m, 0LL)]) > 0)
                    jum2[j - 1]++;
            }
        }
        for(ll i = 0; i < n * m; i++)
            cout << jum1[i] + jum2[i] << " ";
        cout << "\n";
    }
}