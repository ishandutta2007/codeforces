#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int d[N];
vector < pair < int, int > > v[N];

void dfs(int x, int p)
{
        for(auto y: v[x]){
                if(y.fi == p){
                        continue;
                }
                dfs(y.fi, x);
                d[x] = max(d[x], d[y.fi] + y.se);
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y, c;
                cin >> x >> y >> c;
                v[x].pb({y, c});
                v[y].pb({x, c});
        }
        dfs(0, 0);
        cout << d[0] << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}