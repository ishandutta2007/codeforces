#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, l, a[100001], dp[100001];

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    l=1e18;
    a[0]=0;
    for (int i = 1; i < n; i++)
        if (i>=m)
        {
            k=k+a[i]-a[i-m];
            l=min(l,k);
        }
         else
        {
            k+=a[i];
        }
    cout << l;
	return 0;
}