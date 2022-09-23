#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int s[N];
vector < int > v[N];

void dfs(int x, int p)
{
        s[x] = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                s[x] += s[y];
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, -1);
        if(n % 2){
                cout << -1 << "\n";
                return;
        }
        int cnt = 0;
        for(int i = 2; i <= n; i++){
                cnt += 1 - s[i] % 2;
        }
        cout << cnt << "\n";
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