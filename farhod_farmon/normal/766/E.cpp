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

int n;
int a[N];
int b[N];
int d[N][2];
ll cnt;
vector < int > v[N];

void dfs(int x, int p)
{
        d[x][b[x]] = 1;
        d[x][1 - b[x]] = 0;
        for(int y: v[x])
        {
                if(y == p)
                {
                        continue;
                }
                dfs(y, x);
                cnt += 1ll * d[x][0] * d[y][1];
                cnt += 1ll * d[x][1] * d[y][0];
                d[x][0] += d[y][b[x]];
                d[x][1] += d[y][1 - b[x]];
        }
}

void solve()
{
        cin >> n;
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
                cin >> a[i];
                ans += a[i];
        }
        for(int i = 1; i < n; i++)
        {
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        for(int h = 0; (1 << h) < 1e6; h++)
        {
                for(int i = 1; i <= n; i++)
                {
                        if((1 << h) & a[i])
                        {
                                b[i] = 1;
                        }
                        else
                        {
                                b[i] = 0;
                        }
                }
                cnt = 0;
                dfs(1, -1);
                ans += 1ll * cnt * (1 << h);
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