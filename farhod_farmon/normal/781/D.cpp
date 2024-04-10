#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 550;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
bitset < N > a[2][61][N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
        {
                int x, y, t;
                cin >> x >> y >> t;
                a[t][0][x][y] = 1;
        }
        for(int h = 1; h <= 60; h++)
        {
                for(int i = 1; i <= n; i++)
                {
                        for(int j = 1; j <= n; j++)
                        {
                                if(a[0][h - 1][i][j])
                                {
                                        a[0][h][i] |= a[1][h - 1][j];
                                }
                                if(a[1][h - 1][i][j])
                                {
                                        a[1][h][i] |= a[0][h - 1][j];
                                }
                        }
                }
        }
        ll ans = 0;
        bool f = 0;
        bitset < N > c;
        c[1] = 1;
        for(int h = 60; h >= 0; h--)
        {
                bitset < N > nc;
                for(int i = 1; i <= n; i++)
                {
                        if(c[i] == 0)
                        {
                                continue;
                        }
                        nc |= a[f][h][i];
                }
                if(nc.count())
                {
                        ans += (1ll << h);
                        f ^= 1;
                        c = nc;
                }
        }
        if(ans > 1e18)
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