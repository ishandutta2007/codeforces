#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

int inf = 1e9;

int n;
int res;
int a[N];
int d[N][2];
vector < int > v[N];

void dfs(int x, int p)
{
        d[x][0] = d[x][1] = -inf;

        if(a[x] == 1){
                d[x][0] = 1;
        } else if(a[x] == 2){
                d[x][1] = 1;
        }
        vector < int > A(2, 0);
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                for(int i = 0; i < 2; i++){
                        d[x][i] = max(d[x][i], d[y][i]);
                }
                if(a[x] == 1){
                        d[x][0] = max(d[x][0], d[y][1] + 1);
                        res = max(res, A[1] + d[y][1] + 1);
                } else if(a[x] == 2){
                        d[x][1] = max(d[x][1], d[y][0] + 1);
                        res = max(res, A[0] + d[y][0] + 1);
                }

                for(int i = 0; i < 2; i++){
                        res = max(res, d[y][i] + A[i ^ 1]);
                }
                for(int i = 0; i < 2; i++){
                        A[i] = max(A[i], d[y][i]);
                }
        }
        res = max(res, d[x][0]);
        res = max(res, d[x][1]);
}

void solve()
{
        res = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                v[i].clear();
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);

        cout << res - ((res + 1) / 2) + 1 << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}