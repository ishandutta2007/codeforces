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

ll n, m, j, o, l, k, r, x, y, ans=0, a[300001];
vector <ll> v;
ll t[1000001];
vector <ll> c[300001];

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[y].pb(x);
    }
    ll k=1, ans=0;
    for (int j = 0; j < c[a[n-1]].size(); j++) t[c[a[n-1]][j]]++;
    for (int i = n-2; i > -1; i--)
    {
        if (t[a[i]]==k)
        {
            ans++;
        } else
        {
            k++;
            for (int j = 0; j < c[a[i]].size(); j++) t[c[a[i]][j]]++;
        }
    }
    cout << ans;
    return 0;
}