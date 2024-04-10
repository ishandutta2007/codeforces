#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define ld long double
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, k, l, r, a[11], dp[1001][1001];
vector <pll> b;

int main()
{
    //freopen("brick.in","r",stdin);
    //freopen("brick.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[x]++;
    }
    if (a[2]) {cout << "2 ";a[2]--;}
    ll o=0;
    if (a[1]%2==0 && a[1]>0) a[1]--, o++;
    for (int i = 0; i < a[1]; i++)  cout << "1 ";
    for (int i = 0; i < a[2]; i++)  cout << "2 ";
    if (o) cout << "1";
    return 0;
}