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
const long long MX = 200200;
const long long MAGIC = 250;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int cnt;
int l[N];
int r[N];
int v[N];
bool used[N];
map < int, bool > can;

void dfs(int x, int tl, int tr)
{
        if(x == -1)
        {
                return;
        }
        if(tl <= v[x] && v[x] <= tr)
        {
                can[v[x]] = true;
        }
        dfs(l[x], tl, min(tr, v[x] - 1));
        dfs(r[x], max(tl, v[x] + 1), tr);
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> v[i] >> l[i] >> r[i];
                used[max(0, l[i])] = true;
                used[max(0, r[i])] = true;
        }
        for(int i = 1; i <= n; i++)
        {
                if(used[i] == false)
                {
                        dfs(i, 0, 1e9);
                }
        }
        for(int i = 1; i <= n; i++)
        {
                cnt += can[v[i]];
        }
        cout << n - cnt << endl;
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