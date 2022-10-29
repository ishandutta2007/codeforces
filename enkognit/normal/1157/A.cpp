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

ll n, m, i, j, Q, k, l, T, a[300001], d[2000001], g[2000001];
vector <ll> b;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll ans=9;
    if (n%10==0) n++,ans++;
    while (n)
    {
        while (n%10==0) n/=10;
        if (n<10) break;
        ans+=10-n%10;
        n+=10-n%10;
        //cout << n << "\n";
    }
    cout << ans;
}