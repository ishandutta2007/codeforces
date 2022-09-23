#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 500500;

using namespace std;

int n;
int a[N];
int d[N][20];
vector < int > v[N];

void dfs(int x, int p)
{
        d[x][0] = p;
        for(int i = 1; i < 20; i++){
                d[x][i] = d[d[x][i - 1]][i - 1];
        }
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int root = 1;
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i] < a[root]){
                        root = i;
                }
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(root, root);
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                if(i == root){
                        continue;
                }
                long long mn = 1e18;
                for(int j = 0; j < 20; j++){
                        mn = min(mn, 1ll * (j + 1) * a[d[i][j]]);
                }
                ans += a[i] + mn;
        }
        cout << ans << "\n";
}