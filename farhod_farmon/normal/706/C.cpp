#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll c[N];
ll d[N][2];
string s[N];
string ts[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> c[i];
        }
        for(int i = 1; i <= n; i++)
        {
                cin >> s[i];
                ts[i] = s[i];
                reverse(ts[i].begin(), ts[i].end());
        }
        d[n][1] = c[n];
        for(int i = n - 1; i >= 1; i--)
        {
                d[i][0] = d[i][1] = 1e18;
                if(s[i] <= s[i + 1])
                {
                        d[i][0] = min(d[i][0], d[i + 1][0]);
                }
                if(s[i] <= ts[i + 1])
                {
                        d[i][0] = min(d[i][0], d[i + 1][1]);
                }
                if(ts[i] <= s[i + 1])
                {
                        d[i][1] = min(d[i][1], d[i + 1][0] + c[i]);
                }
                if(ts[i] <= ts[i + 1])
                {
                        d[i][1] = min(d[i][1], d[i + 1][1] + c[i]);
                }
        }
        ll ans = min(d[1][0], d[1][1]);
        if(ans == 1e18)
        {
                ans = -1;
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