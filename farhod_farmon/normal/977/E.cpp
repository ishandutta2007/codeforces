#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
bool used[N];
vector < int > g;
vector < int > v[N];

void dfs(int x)
{
        if(used[x]){
                return;
        }
        g.push_back(x);
        used[x] = 1;
        for(int y: v[x]){
                dfs(y);
        }
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
                if(used[i]){
                        continue;
                }
                g.clear();
                dfs(i);
                int cnt = 0, col = 0;
                for(int x: g){
                        cnt += (int)(v[x].size());
                        col += (int)(v[x].size()) == 2;
                }
                cnt /= 2;
                if(cnt == (int)(g.size()) && col == (int)(g.size())){
                        ans++;
                }
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}