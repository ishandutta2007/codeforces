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
ll cnt[2];
ll d[110][110][2][2][2];
ll depe(ll E, ll O, ll pA, ll pB, ll gil)
{
    if(E == 0 && O == 0)
    {
        if(gil == 0)
        {
            return (pA == 0);
        }
        else
        {
            return (pA == 1);
        }
    }
    ll &ret = d[E][O][pA][pB][gil];
    if(ret == -1)
    {
        ret = 0;
        if(gil == 0)
        {
            if(E > 0 && depe(E - 1, O, pA, pB, 1) == 0)
                ret = 1;
            if(O > 0 && depe(E, O - 1, 1 - pA, pB, 1) == 0)
                ret = 1;
        }
        else
        {
            if(E > 0 && depe(E - 1, O, pA, pB, 0) == 0)
                ret = 1;
            if(O > 0 && depe(E, O - 1, pA, 1 - pB, 0) == 0)
                ret = 1;
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    memset(d, -1, sizeof(d));
    while(t--)
    {
        ll n;
        cnt[0] = 0;
        cnt[1] = 0;
        cin >> n;
        for(ll i = 0; i < n; i++)
        {
            ll ta;
            cin >> ta;
            cnt[ta&1]++;
        }
        if(depe(cnt[0], cnt[1], 0, 0, 0))
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}