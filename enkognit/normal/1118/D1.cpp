#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, j, o, l, r, x, y, a[1000001], b[1001][1001];
set<ll> s;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    ll l=1, r=n+1;
    while (l<r)
    {
        ll w=(l+r)/2;
        ll ans=0;
        //cout << l << " " << r << "\n";
        for (int i = 1; i <= n; i++) ans+=max(a[i]-(i-1)/w,0ll);
        //cout << w << " " << ans << "\n";
        if (ans<m) l=w+1; else r=w;
    }
    if (l==n+1) cout << -1; else cout << l;
    return 0;
}