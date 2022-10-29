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

ll n, m, i, j, Q, k, l, dp[300001], a[300001], pref[300001];string s;
vector <ll> v, ans;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    ll p1=0, p2=0, l1=0, l2=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i]%2) p1++; else p2++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        if (a[i]%2) l2++; else l1++;
    }
    cout << min(l1,p1)+min(l2,p2);
}
/*
10 11
1 2
1 3
1 4
3 4
2 5
2 6
5 6
3 7
4 8
5 9
6 10
*/