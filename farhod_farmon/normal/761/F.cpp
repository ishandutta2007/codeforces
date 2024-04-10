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
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int k;
int a[MX];
int b[MX];
int c[MX];
int d[MX];
ll na[N][N];
ll s[26][N][N];
int f[26][N][N];
char e[MX];
char sh[N][N];


void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++)
        {
                for(int j = 1; j <= m; j++)
                {
                        cin >> sh[i][j];
                }
        }
        for(int i = 1; i <= k; i++)
        {
                cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
                e[i] -= 'a';
                f[e[i]][a[i]][b[i]]++;
                f[e[i]][a[i]][d[i] + 1]--;
                f[e[i]][c[i] + 1][b[i]]--;
                f[e[i]][c[i] + 1][d[i] + 1]++;
        }
        for(int h = 0; h < 26; h++)
        {
                for(int i = 1; i <= n; i++)
                {
                        for(int j = 1; j <= m; j++)
                        {
                                f[h][i][j] += f[h][i - 1][j] + f[h][i][j - 1] - f[h][i - 1][j - 1];
                        }
                }
        }
        ll all = 0;
        for(int i = 1; i <= n; i++)
        {
                for(int j = 1; j <= m; j++)
                {
                        ll up = 0;
                        ll down = 0;
                        ll cup = 0;
                        ll cdown = 0;
                        for(int h = 0; h < 26; h++)
                        {
                                up += h * f[h][i][j];
                                cup += f[h][i][j];
                        }
                        for(int h = 0; h < 26; h++)
                        {
                                s[h][i][j] = cdown * h - down + up - cup * h;
                                s[h][i][j] += (k - cdown - cup) * abs(h - (sh[i][j] - 'a'));
                                if(h == sh[i][j] - 'a')
                                {
                                        na[i][j] = s[h][i][j];
                                        all += na[i][j];
                                        na[i][j] += na[i - 1][j] + na[i][j - 1] - na[i - 1][j - 1];
                                }
                                s[h][i][j] += s[h][i - 1][j];
                                s[h][i][j] += s[h][i][j - 1];
                                s[h][i][j] -= s[h][i - 1][j - 1];
                                down += h * f[h][i][j];
                                cdown += f[h][i][j];
                                up -= h * f[h][i][j];
                                cup -= f[h][i][j];
                        }
                }
        }
        ll ans = 1e18;
        for(int i = 1; i <= k; i++)
        {
                ll cnt = all;
                cnt -= na[c[i]][d[i]] - na[a[i] - 1][d[i]] - na[c[i]][b[i] - 1] + na[a[i] - 1][b[i] - 1];
                cnt += s[e[i]][c[i]][d[i]] - s[e[i]][a[i] - 1][d[i]] - s[e[i]][c[i]][b[i] - 1] + s[e[i]][a[i] - 1][b[i] - 1];
                ans = min(ans, cnt);
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