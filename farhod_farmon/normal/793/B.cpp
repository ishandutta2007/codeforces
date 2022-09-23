#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long MX = 2020;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int d[N][N][4];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char c[N][N];

void solve()
{
        int x = 0, y = 0;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
                for(int j = 1; j <= m; j++)
                {
                        cin >> c[i][j];
                        if(c[i][j] == 'S')
                        {
                                x = i;
                                y = j;
                        }
                        for(int h = 0; h < 4; h++)
                        {
                                d[i][j][h] = 1e9;
                        }
                }
        }
        queue < pair < pair < int, int >, int > > q;
        q.push({{x, y}, 0});
        q.push({{x, y}, 1});
        q.push({{x, y}, 2});
        q.push({{x, y}, 3});
        for(int i = 0; i < 4; i++)
        {
                d[x][y][i] = 0;
        }
        while(!q.empty())
        {
                x = q.front().fi.fi;
                y = q.front().fi.se;
                int h = q.front().se;
                q.pop();
                for(int j = 0; j < 4; j++)
                {
                        int nx = x + dx[j], ny = y + dy[j];
                        if(nx < 1 || ny < 1 || nx > n || ny > m || c[nx][ny] == '*')
                        {
                                continue;
                        }
                        if(d[x][y][h] + (j != h) < d[nx][ny][j])
                        {
                                d[nx][ny][j] = d[x][y][h] + (j != h);
                                q.push({{nx, ny}, j});
                        }
                }
        }
        for(int i = 1; i <= n; i++)
        {
                for(int j = 1; j <= m; j++)
                {
                        if(c[i][j] == 'T')
                        {
                                int ans = 1e9;
                                for(int h = 0; h < 4; h++)
                                {
                                        ans = min(ans, d[i][j][h]);
                                }
                                if(ans <= 2)
                                {
                                        cout << "YES" << endl;
                                }
                                else
                                {
                                        cout << "NO" << endl;
                                }
                                return;
                        }
                }
        }
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