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
ll b[NN], IN[NN];
vector<ll> v[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            IN[i] = 0;
            v[i].clear();
        }
        vector<ll> z;
        for(ll i = 1; i <= n; i++)
        {
            b[i] = 0;
            ll ta;
            cin >> ta;
            while(ta--)
            {
                ll tb;
                cin >> tb;
                v[tb].pb(i);
                IN[i]++;
            }
            if(IN[i] == 0)
                z.pb(i);
        }
        ll has = 0;
        while(1)
        {
            priority_queue<ll> pq;
            ll lst = 0;
            for(auto isi : z)
                pq.push(-isi);
            z.clear();
            if(pq.empty())
                break;
            has++;
            while(!pq.empty())
            {
                ll pos = -pq.top();
                pq.pop();
                if(pos <= lst)
                {
                    z.pb(pos);
                    continue;
                }
                lst = pos;
                // cout << pos << "_\n";
                b[pos] = 1;
                for(ll i = 0; i < v[pos].size(); i++)
                {
                    ll nx = v[pos][i];
                    IN[nx]--;
                    if(IN[nx] == 0)
                        pq.push(-nx);
                }
            }
        }
        for(ll i = 1; i <= n; i++)
            if(b[i] == 0)
                has = -1;
        cout << has << "\n";
    }
}