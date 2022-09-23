#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 500500;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll m;

void solve()
{
    cin >> n >> m;
    ll kmax = (n - m + 1) * (n - m) / 2;
    ll g = (n - 1) / m + 1;
    ll kmin = g * (g - 1) / 2 * (n % m == 0 ? m : n % m) + (g - 1) * (g - 2) / 2 * ((m - n % m) % m);
    cout << kmin << " " << kmax << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t = 1;
    if(mtest)
        cin >> t;
    while(t--)
        solve();
}