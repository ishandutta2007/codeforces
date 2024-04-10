#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, m, i, j, Q, k, l, T, a[300002];
vector <ll> v[200002];

int main()
{
    //freopen("relocate.in","r",stdin);
    //freopen("relocate.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll p = 0, ans = 0;

    for (int i = n-1; i > -1; i--)
    {
        p += a[i] / 2;
        if (a[i] % 2 && p)
        {
            p--;
            ans++;
        }
    }
    ans+=p*2/3;
    cout << ans;
}
/*
7 9
1 2
2 3
3 4
4 5
5 6
1 6
2 6
3 5
3 7
*/