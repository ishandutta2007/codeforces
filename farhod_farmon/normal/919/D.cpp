#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int m;
int ans;
int cycle;
int a[N];
int used[N];
int d[N][26];
vector < int > v[N];

void dfs(int x)
{
        if(used[x] == 1){
                cycle = 1;
                return;
        }
        if(used[x]){
                return;
        }
        used[x] = 1;
        for(int y: v[x]){
                dfs(y);
                for(int i = 0; i < 26; i++){
                        d[x][i] = max(d[x][i], d[y][i]);
                }
        }
        d[x][a[x]]++;
        for(int i = 0; i < 26; i++){
                ans = max(ans, d[x][i]);
        }
        used[x] = 2;
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                a[i] = c - 'a';
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
        }
        for(int i = 1; i <= n; i++){
                if(used[i] == 0){
                        dfs(i);
                }
        }
        if(cycle == 1){
                ans = -1;
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}