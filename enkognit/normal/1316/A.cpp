#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;

ll n, T, kl = 0, m;

void solve()
{
    ll n, k=0, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        k += x;
    }
    cout << min(k,m) << "\n";
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
6
add 1
sum 1 1
add 3
add 1
sum 2 3
sum 1 2
*/