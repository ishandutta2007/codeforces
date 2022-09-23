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
const long long MX = 1000100;
const long long MAGIC = 1000;
const long long mod = 1e9 + 9;

using namespace std;

int n;
int d[N];
int h[N];
int f[N];
vector < int > v[N];

void dfs(int x, int p)
{
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                h[y] = h[x] + 1;
                dfs(y, x);
                f[x] = max(f[x], f[y] + 1);
        }
}

void solve()
{
        int s;
        cin >> n >> s;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        for(int i = 1; i <= n; i++){
                d[i] = 1e9;
        }
        queue < int > q;
        q.push(s);
        d[s] = 0;
        while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int y: v[x]){
                        if(d[y] == 1e9){
                                d[y] = d[x] + 1;
                                q.push(y);
                        }
                }
        }
        dfs(1, 1);
        int ans = 0;
        for(int i = 1; i <= n; i++){
                if(d[i] < h[i]){
                        ans = max(ans, (f[i] + h[i]) * 2);
                }
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("fcount.in");
        //fout("fcount.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}