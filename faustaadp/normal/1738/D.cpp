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
ll cnt[NN], a[NN];
vector<ll> v[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n;
        for(ll i = 0; i <= n + 1; i++)
        {
            cnt[i] = 0;
            v[i].clear();
        }
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
            v[a[i]].pb(i);
        }
        priority_queue<pll> pq;
        ll cek = 0;
        ll ma = 0;
        if(cnt[0])
        {
            for(auto z : v[0])
            {
                pq.push(mp(-cnt[z], z));
            }
        }
        else
        if(cnt[n + 1])
        {
            cek = 1;
            for(auto z : v[n + 1])
            {
                pq.push(mp(-cnt[z], z));
            }
        }
        vector<ll> jaw;
        while(!pq.empty())
        {
            vector<ll> cal;
            while(!pq.empty())
            {
                jaw.pb(pq.top().se);
                cal.pb(pq.top().se);
                if(cek)
                    ma = max(ma, pq.top().se);
                // cout << pq.top().se << "@\n";
                pq.pop();
            }
            for(auto xx : cal)
                for(auto yy : v[xx])
                    pq.push(mp(-cnt[yy], yy));
            cek = 1 - cek;
        }
        n = jaw.size();
        cout << ma << "\n";
        for(ll i = 0; i < n; i++)
        {
            if(i < n - 1)
                cout << jaw[i] << " ";
            else
                cout << jaw[i] << "\n";
        }

        // for(ll i = 1; i <= n; i++)
        // {
        //     ll x = a[i];
        //     if(x <= k)
        //     {
        //         b[x] = n + 1;
        //         for(ll j = i - 1; j >= 1; j--)
        //             if(a[j] > k)
        //             {
        //                 b[x] = a[j];
        //                 break;
        //             }
        //     }
        //     else
        //     {
        //         b[x] = 0;   
        //         for(ll j = i - 1; j >= 1; j--)
        //             if(a[j] <= k)
        //             {
        //                 b[x] = a[j];
        //                 break;
        //             }
        //     }
        // }
        // for(ll i = 1; i <= n; i++)
        //     cout << b[i] << " ";
        // cout << "\n";
        // for(ll i = 1; i <= n; i++)
        //     cout << b[a[i]] << " ";
        // cout << "\n\n";
    }
}