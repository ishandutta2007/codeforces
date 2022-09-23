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
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int k;
int g = 1;
int p[N];
bool used[N];
vector < int > v[N];
vector < int > ans[N];

void add(int x)
{
        if(ans[g].size() == (n + n - 1) / k + 1)
                g++;
        ans[g].pb(x);
}

void dfs(int x, int p)
{
        add(x);
        used[x] = true;
        for(int y: v[x])
        {
                if(used[y] == false)
                {
                        dfs(y, x);
                }
        }
        if(p != -1)
                add(p);
}

void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= m; i++)
        {
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        dfs(1, -1);
        assert(g <= k);
        for(int i = 1; i <= k; i++)
        {
                if(ans[i].empty())
                        ans[i].pb(1);
                cout << ans[i].size() << " ";
                for(int x: ans[i])
                        cout << x << " ";
                cout << endl;
        }
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