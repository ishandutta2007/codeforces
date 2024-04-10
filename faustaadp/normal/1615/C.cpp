#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 1e9 + 7;
const ll inf = (ll)1e18 + 1;
ll cnt[2][2];
char a[NN], b[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cnt[0][0] = 0;
        cnt[0][1] = 0;
        cnt[1][0] = 0;
        cnt[1][1] = 0;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i <= n; i++)
            cin >> b[i];
        for(ll i = 1; i <= n; i++)
            cnt[a[i] - '0'][b[i] - '0']++;
        // cout << cnt[0][0] << " " << cnt[0][1] << " " << cnt[1][0] << " " << cnt[1][1] << "\n";
        ll has = 1e18;
        if(((cnt[0][0] + cnt[1][1]) % 2 == 1) && (cnt[1][1] - cnt[0][0] == 1))
            has = min(has, cnt[0][0] + cnt[1][1]);
        if(((cnt[0][1] + cnt[1][0]) % 2 == 0) && (abs(cnt[0][1] - cnt[1][0]) == 0))
            has = min(has, cnt[0][1] + cnt[1][0]);
        if(has == 1e18)
            has = -1;
        cout << has << "\n";
    }
}