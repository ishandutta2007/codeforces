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
const ll inf = 1e18;
ll t, n, q, a[NN], pr[NN];
vector<ll> f[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(ll i = 2; i <= 200000; i++)
        for(ll j = i * i; j <= 200000; j += i)
            pr[j] = 1;
    // for(ll i = 1; i <= 10; i++)
        // cout << i << " " << pr[i] << "_\n";
    cin >> t;
    while(t--)
    {
        priority_queue<ll> pq1, pq2;
        vector<ll> isi;
        cin >> n >> q;
        for(ll i = n - 1; i > 0; i--)
        {
            if(n % i == 0)
            {
                ll boleh = 1;
                for(ll j = 0; j < isi.size(); j++)
                {
                    if(isi[j] % i == 0)
                    {
                        boleh = 0;
                        break;
                    }
                }
                if(boleh)
                {
                    isi.pb(i);
                }
            }
        }
        ll sz = isi.size();
        for(ll i = 0; i < n; i++)
            cin >> a[i];
        for(ll i = 0; i < sz; i++)
        {
            f[i].clear();
            ll X = isi[i];
            for(ll j = 0; j < X; j++)
                f[i].pb(0);
            for(ll j = 0; j < n; j++)
            {
                f[i][j % X] += a[j] * X;
            }
            for(ll j = 0; j < X; j++)
            {
                pq1.push(f[i][j]);
            }
        }
        ll ma = 0;
        cout << pq1.top() << "\n";
        while(q--)
        {
            ll ta, tb;
            cin >> ta >> tb;
            ta--;
            ma = 0;
            if(a[ta] != tb)
            {
                for(ll i = 0; i < sz; i++)
                {
                    ll X = isi[i];
                    ll Y = ta % X;
                    pq2.push(f[i][Y]);
                    f[i][Y] -= (a[ta] - tb) * X;
                    pq1.push(f[i][Y]);
                    while((!pq1.empty()) && (!pq2.empty()) && pq1.top() == pq2.top())
                    {
                        pq1.pop();
                        pq2.pop();
                    }
                }
                a[ta] = tb;
            }
            cout << pq1.top() << "\n";
        }
    }
}


    // n = 1;
    // for(ll n = 1; n <= 20; n++)
    // {
    //     cout << "N = " << n << "\n";
    //     for(ll i = 1; i < n; i++)
    //     {
    //         for(ll j = 1; j <= n; j++)
    //         {
    //             x[i * j % n]++;
    //             // cout << i * j % n << " ";
    //         }
    //         for(ll j = 0; j < n; j++)
    //         {
    //             cout << x[j] << " ";
    //             x[j] = 0;
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }