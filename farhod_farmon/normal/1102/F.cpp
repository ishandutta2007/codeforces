#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 16;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int a[N][10010];
int cost[N][N];
int gg[N][N];
int d[1 << N][N];

int solve(int st)
{
        for(int i = 0; i < (1 << n); i++){
                for(int j = 0; j < n; j++){
                        d[i][j] = -1;
                }
        }
        d[1 << st][st] = 1e9;
        for(int i = 1; i < (1 << n); i++){
                for(int j = 0; j < n; j++){
                        if(d[i][j] == -1){
                                continue;
                        }
                        for(int h = 0; h < n; h++){
                                if((1 << h) & i){
                                        continue;
                                }
                                int ni = i | (1 << h);
                                d[ni][h] = max(d[ni][h], min(d[i][j], cost[j][h]));
                        }
                }
        }
        int res = 0;
        int en = (1 << n) - 1;
        for(int i = 0; i < n; i++){
                res = max(res, min(d[en][i], gg[i][st]));
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        cin >> a[i][j];
                }
                for(int j = 0; j < n; j++){
                        cost[i][j] = 1e9;
                        gg[i][j] = 1e9;
                }
        }
        for(int j = 0; j < m; j++){
                for(int i = 0; i < n; i++){
                        for(int h = 0; h < n; h++){
                                cost[i][h] = min(cost[i][h], abs(a[i][j] - a[h][j]));
                                if(j + 1 < m){
                                        gg[i][h] = min(gg[i][h], abs(a[i][j] - a[h][j + 1]));
                                }
                        }
                }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
                res = max(res, solve(i));
        }
        cout << res << "\n";
}