#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int t;
int s[N];
bool used[N];
vector < int > v[N];

void dfs(int x, int p)
{
        if(x == t){
                used[x] = 1;
        }
        s[x] = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                s[x] += s[y];
                used[x] |= used[y];
        }
}

void solve()
{
        int x, y;
        cin >> n >> x >> y;
        t = y;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(x, x);
        int f = n;
        for(int y: v[x]){
                if(used[y]){
                        f -= s[y];
                }
        }
        cout << 1ll * n * (n - 1) - 1ll * f * s[y] << "\n";
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