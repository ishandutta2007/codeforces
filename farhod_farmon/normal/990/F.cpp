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
int m;
int a[N];
int ans[N];
int A[N];
int B[N];
bool used[N];
vector < pair < int, int > > v[N];

void dfs(int x, int h)
{
        used[x] = 1;
        for(auto y: v[x]){
                if(!used[y.fi]){
                        dfs(y.fi, y.se);
                }
        }
        if(h == -1){
                if(a[x] != 0){
                        cout << "Impossible" << "\n";
                        exit(0);
                }
        }
        else{
                int y = A[h] ^ B[h] ^ x;
                a[y] += a[x];
                if(A[h] == x){
                        ans[h] = -a[x];
                }
                else{
                        ans[h] = a[x];
                }
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        cin >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                A[i] = x; B[i] = y;
                v[x].push_back({y, i});
                v[y].push_back({x, i});
        }
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        dfs(i, -1);
                }
        }
        cout << "Possible" << "\n";
        for(int i = 1; i <= m; i++){
                cout << ans[i] << "\n";
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