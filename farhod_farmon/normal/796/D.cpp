#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long MX = 200200;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int k;
int d[N];
bool used[N];
vector < int > po;
vector < pair < int, int > > v[N];

bool f(int mi)
{
        vector < int > q;
        for(int i = 1; i <= n; i++)
        {
                d[i] = 1e9;
                used[i] = 0;
        }
        for(int x: po)
        {
                d[x] = 0;
                q.pb(x);
        }
        for(int i = 0; i < q.size(); i++)
        {
                int x = q[i];
                if(d[x] == mi)
                {
                        continue;
                }
                for(auto p: v[x])
                {
                        if(d[p.fi] == 1e9)
                        {
                                d[p.fi] = d[x] + 1;
                                used[p.se] = true;
                                q.pb(p.fi);
                        }
                }
        }
        for(int i = 1; i <= n; i++)
        {
                if(d[i] == 1e9)
                {
                        return false;
                }
        }
        return true;
}

void solve()
{
        sc("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= m; i++)
        {
                int x;
                sc("%d", &x);
                po.pb(x);
        }
        for(int i = 1; i < n; i++)
        {
                int x, y;
                sc("%d%d", &x, &y);
                v[x].pb({y, i});
                v[y].pb({x, i});
        }
        int l = 0, r = k;
        while(l < r)
        {
                int mi = (l + r) / 2;
                if(f(mi))
                {
                        r = mi;
                }
                else
                {
                        l = mi + 1;
                }
        }
        f(l);
        vector < int > ans;
        for(int i = 1; i < n; i++)
        {
                if(!used[i])
                {
                        ans.pb(i);
                }
        }
        pr("%d\n", ans.size());
        for(int x: ans)
        {
                pr("%d ", x);
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