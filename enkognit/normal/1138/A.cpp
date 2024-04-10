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

ll n, m, j, o, l, r, x, y, ans=0, b[100001], c[100001];
ll a[100001];
ll dp[1001][1001];

ll fact(ll h)
{
    if (h<2) return 1; else return fact(h-1)%(ll)(1e9+7);
}

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){cin >> a[i];if (a[i]==2) b[i]=b[i-1]+1; else c[i]=c[i-1]+1;}
    for (int i = 1; i <= n; i++)
    {
        if (i>=c[i]*2)
        {
            if (b[i-c[i]]-b[i-c[i]*2]==c[i]) ans=max(c[i],ans);
        }
        if (i>=b[i]*2)
        {
            if (c[i-b[i]]-c[i-b[i]*2]==b[i]) ans=max(b[i],ans);
        }
    }
    cout << ans*2;
    return 0;
}