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

const ll MOD=1000000007;

ll n, m, w, l, r, ans, k, sum;
vector <ll> a,b;
bool t[1000001];

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        b.pb(x);
        w+=x;
    }
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        a.pb(x);
        sum+=x;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    if (a[0]<b[0]) {cout << -1;exit(0);}
    if (b[0]==a[0]) {cout << sum+(w-b[0])*m;exit(0);}
    if (n==1) {cout << -1;exit(0);}
    cout << sum+b[0]+b[1]*(m-1)+(w-b[0]-b[1])*m;
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