#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, m, a[NN], b[NN], c[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
            c[i] = 0;
        }
        priority_queue<pair<ll, ll> > pq;
        for(ll i = 1; i <= n; i++)
        {
            // cout << max(a[i], b[i]) << "__\n";
            pq.push(mp(max(a[i], b[i]), i));
        }
        ll has = 0;
        ll hz = 0;
        ll masih = m;
        while(1)
        {
            if(pq.empty() || masih == 0)
                break;
            ll idx = pq.top().se;
            pq.pop();
            // cout << pq.top().fi << "_!\n";
            // cout << idx << " " << a[idx] << " " << b[idx] << " " << c[idx] << "_\n";
            if(c[idx] == 0)
            {
                c[idx] = 1;
                if(a[idx] > b[idx])
                {
                    masih--;
                    hz += a[idx];
                    pq.push(mp(b[idx], idx));
                }
                else
                {
                    has = max(has, hz + a[idx] + (masih - 1) * b[idx]);
                }
            }
            else
            {
                has = max(has, hz + masih * b[idx]);
                break;
            }
            has = max(has, hz);
        }
        cout << has << "\n";
    }
}