#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 111;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
char c[N];
long long d[N][N][N];

long long solve(int l, int r, int k)
{
        long long &res = d[l][r][k];
        if(res != -1){
                return res;
        }
        if(l > r){
                return res = 0;
        }
        if(l == r){
                return res = a[k];
        }
        res = solve(l + 1, r, 1) + a[k];
        if(c[r] == c[l]){
                res = max(res, solve(l, r - 1, k + 1));
        }
        for(int i = l + 1; i < r; i++){
                if(c[i] == c[l]){
                        res = max(res, solve(l + 1, i - 1, 1) + solve(i, r, k + 1));
                }
        }
        if(k == 1){
                for(int i = l; i < r; i++){
                        res = max(res, solve(l, i, 1) + solve(i + 1, r, 1));
                }
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                        for(int h = 0; h < N; h++){
                                d[i][j][h] = -1;
                        }
                }
        }
        cout << solve(1, n, 1) << "\n";
}