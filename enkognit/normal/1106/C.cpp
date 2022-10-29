#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))

using namespace std;

ll n, m, i, j, k, l, r, kol, ans;
ll a[300001];
map<ll,ll> t;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= n/2; i++) ans+=sqr(a[i]+a[n-i+1]);
    cout << ans;
    return 0;
}
/*
7 2
1 1 1 1 1 3 3
1 2 3 3 1 1
*/