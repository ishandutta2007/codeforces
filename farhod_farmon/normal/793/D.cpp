#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 81;
const long long MX = 2020;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int m;
int d[N][N][N][N];
bool used[N][N][N][N];
vector < pair < int, int > > v[N];

int get(int x, int l, int r, int need)
{
        if(need == 0)
        {
                return 0;
        }
        if(l > r || r - l + 1 < need)
        {
                return 1e9;
        }
        if(used[x][l][r][need])
        {
                return d[x][l][r][need];
        }
        int cnt = 1e9;
        for(auto p: v[x])
        {
                if(p.fi < l || p.fi > r)
                {
                        continue;
                }
                if(p.fi > x)
                {
                        cnt = min(cnt, get(p.fi, x + 1, r, need - 1) + p.se);
                }
                else
                {
                        cnt = min(cnt, get(p.fi, l, x - 1, need - 1) + p.se);
                }
        }
        used[x][l][r][need] = true;
        d[x][l][r][need] = cnt;
        return cnt;
}

void solve()
{
        cin >> n >> k >> m;
        for(int i = 1; i <= m; i++)
        {
                int x, y, c;
                cin >> x >> y >> c;
                v[x].pb({y, c});
        }
        for(int i = 0; i < N; i++)
        {
                for(int j = 0; j < N; j++)
                {
                        for(int h = 0; h < N; h++)
                        {
                                for(int hj = 0; hj < N; hj++)
                                {
                                        d[i][j][h][hj] = 1e9;
                                }
                        }
                }
        }
        int ans = 1e9;
        for(int i = 1; i <= n; i++)
        {
                ans = min(ans, get(i, 1, n, k - 1));
        }
        if(ans == 1e9)
        {
                ans = -1;
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("rmq.in");
        //fout("rmq.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}