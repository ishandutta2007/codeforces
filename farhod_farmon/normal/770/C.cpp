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
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int f;
int need[N];
int used[N];
vector < int > v[N];
vector < int > order;

void dfs(int x)
{
        if(used[x])
        {
                if(used[x] == f)
                {
                        cout << -1 << endl;
                        exit(0);
                }
                return;
        }
        used[x] = f;
        for(int y: v[x])
        {
                dfs(y);
        }
        used[x] = 1e9;
        order.pb(x);
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= k; i++)
        {
                cin >> need[i];
        }
        for(int i = 1; i <= n; i++)
        {
                int l;
                cin >> l;
                v[i].resize(l);
                for(int j = 0; j < l; j++)
                {
                        cin >> v[i][j];
                }
        }
        for(f = 1; f <= k; f++)
        {
                dfs(need[f]);
        }
        cout << order.size() << endl;
        for(int x: order)
        {
                cout << x << " ";
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