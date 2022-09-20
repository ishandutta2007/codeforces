#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200200;

long long inf = 1e18;

int n;
int a[N], b[N];
long long d[N][2];
vector < int > v[N];

void dfs(int x, int p)
{
        d[x][0] = d[x][1] = 0;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                d[x][0] += max(d[y][0] + abs(a[x] - a[y]), d[y][1] + abs(a[x] - b[y]));
                d[x][1] += max(d[y][0] + abs(b[x] - a[y]), d[y][1] + abs(b[x] - b[y]));
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];

                v[i].clear();
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        cout << max(d[1][0], d[1][1]) << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}