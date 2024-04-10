#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 101;
const int mod = 1e9 + 7;

int n, m;
int a[N][N];
int res[N][N];
bool dead[N][N];
bool done[N];

void solve()
{
        cin >> n >> m;
        vector < vector < int > > v;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                        v.push_back({a[i][j], i, j});

                        res[i][j] = dead[i][j] = 0;
                        done[j] = 0;
                }
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < m; i++){
                int x = v[i][1], y = v[i][2];
                dead[x][y] = true;
                res[x][i + 1] = v[i][0];
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1, h = 1; j <= m; j++){
                        if(!res[i][j]){
                                while(dead[i][h]){
                                        h += 1;
                                }
                                res[i][j] = a[i][h];
                                h += 1;
                        }
                        cout << res[i][j] << " ";
                }
                cout << "\n";
        }
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