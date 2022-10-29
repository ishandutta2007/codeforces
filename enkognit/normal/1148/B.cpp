#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, a, b, c, ans, ta, tb, k;

int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> n >> m >> ta >> tb >> k;
    vector <ll> a(n), b(m);
    if (k>=min(n,m)) {cout << -1;exit(0);}
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i <= min(k, n-1); i++)
    {
        ll z=upper_bound(b.begin(), b.end(), a[i]+ta-1)-b.begin();
        if (z+k-i>=m) {cout << -1;exit(0);}
        ans=max(ans, b[z+k-i] + tb);
    }
    cout << ans;
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/