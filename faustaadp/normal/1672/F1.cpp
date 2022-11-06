#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 998244353;
const ll inf = (ll)1e18;
ll n, a[NN], cnt[NN], nx[NN], jaw[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            cnt[i] = 0;
            nx[i] = 0;
        }
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        vector<pll> v;
        for(ll i = 1; i <= n; i++)
            if(cnt[i])
                v.pb(mp(cnt[i], i));
        sort(v.begin(), v.end());
        for(ll i = 1; i < v.size(); i++)
            nx[v[i - 1].se] = v[i].se;
        // for(ll i = 0; i < v.size(); i++)
            // cout << v[i].fi << "  " << v[i].se << "@\n";
            // cout << i << " " << nx[i] << "__\n";
        for(ll i = 1; i <= n; i++)
        {
            if(nx[a[i]])
            {
                jaw[i] = nx[a[i]];
                cnt[nx[a[i]]]--;
            }
        }
        vector<ll> sisa;
        for(ll i = 1; i <= n; i++)
        {
            while(cnt[i])
            {
                sisa.pb(i);
                cnt[i]--;
            }
        }
        for(ll i = 1; i <= n; i++)
        {
            if(nx[a[i]] == 0)
            {
                jaw[i] = sisa.back();
                sisa.pop_back();
            }
        }
        for(ll i = 1; i <= n; i++)
            cout << jaw[i] << " ";
        cout << "\n";
    }
}