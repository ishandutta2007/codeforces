#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pld pair<ll,double>
#define y1 Enkognit

using namespace std;

ll n, m, i, j, k, p, l, r, a[200001], dp[200001];
vector <ll> v, c[200001];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    ll ans=1e18, r=0;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        ll o=x;if  (o<m) o=x+y*((m-x)/y+((m-x)%y>0));
        if (ans>o)ans=o, r=i;
    }
    cout << r+1;
    return 0;
}
/* */