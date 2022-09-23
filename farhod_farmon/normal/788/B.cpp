#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
bool us[N];
bool used[N];
vector < int > v[N];

void dfs(int x)
{
        if(used[x])
        {
                return;
        }
        used[x] = true;
        for(int y: v[x])
        {
                dfs(y);
        }
}

void solve()
{
        sc("%d%d", &n, &m);
        int cnt = 0;
        for(int i = 1; i <= m; i++)
        {
                int x, y;
                sc("%d%d", &x, &y);
                us[x] = us[y] = true;
                if(x == y)
                {
                        cnt++;
                        continue;
                }
                v[x].pb(y);
                v[y].pb(x);
        }
        for(int i = 1; i <= n; i++)
        {
                if(us[i])
                {
                        dfs(i);
                        break;
                }
        }
        for(int i = 1; i <= n; i++)
        {
                if(us[i] && used[i] == false)
                {
                        cout << 0 << endl;
                        return;
                }
        }
        ll ans1 = 1ll * cnt * (cnt - 1) / 2 + 1ll * (m - cnt) * cnt;
        ll ans2 = 0;
        for(int i = 1; i <= n; i++)
        {
                for(int x: v[i])
                {
                        ans2 += v[x].size() - 1;
                }
        }
        cout << ans2 / 2 + ans1 << endl;
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