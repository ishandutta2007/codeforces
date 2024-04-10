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

int n;
int m;
int cc;
int used[N];
vector < int > v[N], g;

void dfs(int x)
{
        if(used[x])
        {
                return;
        }
        used[x] = cc;
        g.pb(x);
        for(int y: v[x])
        {
                dfs(y);
        }
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
        {
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        for(int i = 1; i <= n; i++)
        {
                if(!used[i])
                {
                        cc++;
                        g.clear();
                        dfs(i);
                        ll cnt = 0;
                        for(int x: g)
                        {
                                for(int y: v[x])
                                {
                                        if(used[y] == cc)
                                        {
                                                cnt++;
                                        }
                                }
                        }
                        ll need = 1ll * g.size() * (g.size() - 1);
                        if(need != cnt)
                        {
                                cout << "NO";
                                return;
                        }
                }
        }
        cout << "YES";
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