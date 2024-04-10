#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, t1, t2, k;
vector<pair<ll, ll> > isi;
ll cek(ll A, ll B)
{
    return A * t2 * 100LL + B * t1 * (100LL - k);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> t1 >> t2 >> k;
    for(ll i = 1; i <= n; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        isi.pb(mp(max(cek(ta, tb), cek(tb, ta)), -i));
    }
    sort(isi.begin(), isi.end());
    reverse(isi.begin(), isi.end());
    for(ll i = 0; i < n; i++)
    {
        cout << -isi[i].se << " ";
        cout << fixed << setprecision(2) << isi[i].fi / 100.00 << "\n";
    }
}