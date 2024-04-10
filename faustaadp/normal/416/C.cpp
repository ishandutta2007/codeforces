#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
ll n, a[NN], b[NN], k, c[NN], has;
vector<pair<ll, ll> > isi, isi2;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    cin >> k;
    for(ll i = 1; i <= k; i++)
    {
        ll ta;
        cin >> ta;
        isi.pb(mp(ta, i)); 
    }
    sort(isi.begin(), isi.end());
    priority_queue<pair<ll, ll> > pq;
    for(ll i = 0; i < k; i++)
    {
        for(ll j = 1; j <= n; j++)
            if(c[j] == 0 && a[j] <= isi[i].fi)
            {
                c[j] = 1;
                pq.push(mp(b[j], j));
            }
        if(!pq.empty())
        {
            has += pq.top().fi;
            isi2.pb(mp(pq.top().se, isi[i].se));
            pq.pop();
        }
    }
    cout << isi2.size() << " " << has << "\n";
    for(ll i = 0; i < isi2.size(); i++)
        cout << isi2[i].fi << " " << isi2[i].se << "\n";

}