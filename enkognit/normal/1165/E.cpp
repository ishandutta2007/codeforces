#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=998244353;

ll n, m, w, l, r, ans, k, sum;

bool t[1000001];

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    vector <ll> b(n),a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]*=(i+1)*(n-i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    for (int i = 0; i < n; i++)
    {
        ans=(ans%MOD+((a[i]%MOD)*(b[i]%MOD))%MOD)%MOD;
    }
    cout << ans;
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4

*/