#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500100;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll a[N];
ll d[N][2];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> a[i];
        }
        ll ans = -1e18;
        for(int i = n - 1; i >= 1; i--)
        {
                ll x = abs(a[i] - a[i + 1]);
                d[i][0] = max(0ll, d[i + 1][1]) + x;
                d[i][1] = max(0ll, d[i + 1][0]) - x;
                ans = max(ans, max(d[i][0], d[i][1]));
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("friendcross.in");
        //fout("friendcross.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}