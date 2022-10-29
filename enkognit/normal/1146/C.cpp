#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, Q, k, l, T, d2[100001], w[2];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout <<"1 " << n-1 << " 1";
        for (int i = 2; i <= n; i++) cout << " " << i;
        cout << endl;
        ll k;
        cin >> k;
        ll l=2, r=n;
        while (l<r)
        {
            ll w=(l+r)/2;
            cout <<"1 " << w-l+1 << " 1";
            for (int i = l; i <= w; i++) cout << " " << i;
            cout << endl;
            ll p;
            cin >> p;
            if (p<k) l=w+1; else r=w;
        }
        cout <<"1 " << n-1 << " " << l;
        for (int i = 1; i <= n; i++) if (i!=l)cout << " " << i;
        cout << endl;
        ll p;
        cin >> p;
        cout << "-1 " << p << endl;
    }
}