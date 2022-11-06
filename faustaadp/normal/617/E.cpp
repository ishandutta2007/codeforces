#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e6 + 5;
ll n, q, k, K;
ll a[NN], p[NN], s[NN];
ll pcnt[NN];
ll scnt[NN];
pair<pair<ll, ll>, ll> A[NN];
ll jaw[NN];
bool cmp(pair<pair<ll, ll>, ll> aa, pair<pair<ll, ll>, ll> bb)
{
    ll ka = aa.fi.fi / K; 
    ll kb = bb.fi.fi / K; 
    if(ka < kb)
        return 1;
    else
    if(ka > kb)
        return 0;
    else
    if(ka % 2 == 0)
        return (aa.fi.se < bb.fi.se);
    else
        return (aa.fi.se > bb.fi.se);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q >> k;
    K = sqrt(n);
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    for(ll i = 1; i <= n; i++)
        p[i] = p[i - 1] ^ a[i];
    for(ll i = n; i >= 1; i--)
        s[i] = s[i + 1] ^ a[i];
    for(ll i = 1; i <= q; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        A[i] = mp(mp(ta, tb), i);
    }
    sort(A + 1, A + 1 + q, cmp);
    ll L = 1, R = 0, hz = 0;
    for(ll i = 1; i <= q; i++)
    {
        ll X = A[i].fi.fi;
        ll Y = A[i].fi.se;
        ll idx = A[i].se;
        while(L > X)
        {
            L--;
            pcnt[p[L]]++;
            scnt[s[L]]++;
            hz += pcnt[p[L - 1] ^ k];
        }
        while(R < Y)
        {
            R++;
            pcnt[p[R]]++;
            scnt[s[R]]++;
            hz += scnt[s[R + 1] ^ k];
        }
        while(L < X)
        {
            hz -= pcnt[p[L - 1] ^ k];
            pcnt[p[L]]--;
            scnt[s[L]]--;
            L++;
        }
        while(R > Y)
        {
            hz -= scnt[s[R + 1] ^ k];
            pcnt[p[R]]--;
            scnt[s[R]]--;
            R--;
        }
        jaw[idx] = hz;
    }
    for(ll i = 1; i <= q; i++)
        cout << jaw[i] << "\n";
}