#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 4004;

using namespace std;

int n;
int m;
int a[N];
int s[N];
vector<int> v[N];

int make(int l, int r)
{
        if(l == r){
                return l;
        }
        int best = l;
        for(int i = l; i <= r; i++){
                if(a[i] < a[best]){
                        best = i;
                }
        }
        if(l < best){
                v[best].push_back(make(l, best - 1));
        }
        if(best < r){
                v[best].push_back(make(best + 1, r));
        }
        return best;
}

long long inf = 1e18;
long long d[N][N];

void dfs(int x)
{
        d[x][0] = 0;
        d[x][1] = 1ll * (m - 1) * a[x];

        s[x] = 1;
        for(int y: v[x]){
                dfs(y);

                for(int i = s[x]; i >= 0; i--){
                        for(int j = s[y]; j >= 0; j--){
                                d[x][i + j] = max(d[x][i + j], d[x][i] + d[y][j] - 2ll * i * j * a[x]);
                        }
                }

                s[x] += s[y];
                s[x] = min(s[x], m);
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);


        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                for(int j = 0; j <= m; j++){
                        d[i][j] = - inf;
                }
        }
        int root = make(1, n);
        dfs(root);
        cout << d[root][m] << "\n";
}