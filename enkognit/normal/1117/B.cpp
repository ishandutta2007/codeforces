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

ll n, m, k, j, o, l, r;
ll a[200001];
string s, d;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i< n; i++) cin >> a[i];
    sort(a,a+n);
    ll o=0, ans=0;
    ans+=(m/(k+1))*(k*a[n-1]+a[n-2]);
    m-=(m/(k+1))*(k+1);
    cout << ans+m*a[n-1];
    return 0;
}
/*

*/