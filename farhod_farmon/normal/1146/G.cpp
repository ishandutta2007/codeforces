#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 51;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int k;
int l[N];
int r[N];
int w[N];
int x[N];
int cost[N];
int d[N][N][N];

int get(int l1, int r1, int l2, int r2, int y)
{
        int res = 0;
        for(int i = 1; i <= m; i++){
                if(l1 <= l[i] && l[i] <= r1 && l2 <= r[i] && r[i] <= r2 && x[i] < y){
                        res += w[i];
                }
        }
        return res;
}


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k >> m;
        for(int i = 1; i <= m; i++){
                cin >> l[i] >> r[i] >> x[i] >> w[i];
        }
        for(int i = n; i >= 1; i--){
                for(int j = i; j <= n; j++){
                        for(int h = 0; h <= k; h++){
                                int &res = d[i][j][h];
                                res = -1e9;
                                if(h > 0){
                                        res = d[i][j][h - 1];
                                }
                                if(i == j){
                                        res = max(res, h * h - get(i, i, i, i, h));
                                        continue;
                                }
                                for(int k = 0; k <= h; k++){
                                        cost[k] = 0;
                                }
                                for(int m = i; m <= j; m++){
                                        for(int k = 1; k <= ::m; k++){
                                                if(l[k] >= i && l[k] <= m && r[k] >= m && r[k] <= j){
                                                        cost[x[k] + 1] += w[k];
                                                }
                                        }
                                        for(int k = 0; k <= h; k++){
                                                res = max(res, k * k + d[i][m - 1][k] + d[m + 1][j][k] - cost[k]);
                                                cost[k + 1] += cost[k];
                                                cost[k] = 0;
                                        }
                                }
                        }
                }
        }
        cout << d[1][n][k] << "\n";
}