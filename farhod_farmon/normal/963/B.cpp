#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 3000100;
const long long mod = 1e9 + 9;
const long long block = sqrt(N);

using namespace std;

int n;
bool used[N];
vector < int > ans;
vector < int > v[N];

int dfs(int x, int p)
{
        int cnt = 0;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                cnt += dfs(y, x);
        }
        if(p == -1){
                if(cnt % 2){
                        cout << "NO" << "\n";
                        exit(0);
                }
                used[x] = 1;
                ans.push_back(x);
                return 0;
        }
        if(cnt % 2){
                used[x] = 1;
                ans.push_back(x);
                return 0;
        }
        return 1;
}

void trace(int x, int p)
{
        if(!used[x]){
                ans.push_back(x);
        }
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                trace(y, x);
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int p;
                cin >> p;
                if(p > 0){
                        v[p].push_back(i);
                        v[i].push_back(p);
                }
        }
        int root = 1;
        for(int i = 1; i <= n; i++){
                if(v[i].size() == 1){
                        root = i;
                }
        }
        dfs(root, -1);
        trace(root, -1);
        cout << "YES" << "\n";
        for(int x: ans){
                cout << x << "\n";
        }
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