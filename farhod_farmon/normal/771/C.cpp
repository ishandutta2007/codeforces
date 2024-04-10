#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll k;
ll ans;
ll c[N][6];
ll d[N][6];
vector < int > v[N];

void dfs(int x, int p)
{
        c[x][0]++;
        for(int y: v[x])
        {
                if(y == p)
                {
                        continue;
                }
                dfs(y, x);
                for(int i = 0; i < k; i++)
                {
                        for(int j = 0; j < k; j++)
                        {
                                ans += d[y][j] * c[x][i] + d[x][i] * c[y][j];
                                ans += ((i + j) / k + 1) * (c[x][i] * c[y][j]);
                        }
                }
                for(int i = 1; i < k; i++)
                {
                        d[x][i] += d[y][i - 1];
                        c[x][i] += c[y][i - 1];
                }
                d[x][0] += d[y][k - 1] + c[y][k - 1];
                c[x][0] += c[y][k - 1];
        }
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i < n; i++)
        {
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        dfs(1, 1);
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