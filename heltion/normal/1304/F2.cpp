#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 50;
constexpr int maxm = 20000;
int c[maxn + 2][maxm + 1];
int s[maxn + 2][maxm + 1];
int dp[maxn + 2][maxm + 1];
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
int t[maxm << 2], add[maxm << 2];
void clear(int v, int tl, int tr){
    t[v] = add[v] = 0;
    if(tl < tr){
        clear(ls, tl, tm);
        clear(rs, tm + 1, tr);
    }
}
void update(int v, int x){
    t[v] += x;
    add[v] += x;
}
void push_down(int v){
    update(ls, add[v]);
    update(rs, add[v]);
    add[v] = 0;
}
void update(int v, int tl, int tr, int L, int R, int x){
    if(tl >= L and tr <= R) update(v, x);
    else{
        push_down(v);
        if(L <= tm) update(ls, tl, tm, L, R, x);
        if(R > tm) update(rs, tm + 1, tr, L, R, x);
        t[v] = max(t[ls], t[rs]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1)
            cin >> c[i][j];
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1)
            s[i][j] = s[i][j - 1] + c[i][j];
    int ans = 0;
    for(int i = 1; i <= n; i += 1){
        clear(1, 1, m - k + 1);
        if(i > 1) for(int x = 1; x <= m - k + 1; x += 1){
            if(x <= k)
                update(1, 1, m - k + 1, x, x, s[i][x - 1] - s[i][k] + dp[i - 1][x]);
            else 
                update(1, 1, m - k + 1, x, x, dp[i - 1][x]);
        }
        for(int j = 1; j <= m - k + 1; j += 1){
            if(j > 1){
                if(i > 1){
                    update(1, 1, m - k + 1, max(j - k, 1), j - 1, c[i][j - 1]);
                    update(1, 1, m - k + 1, j, j + k - 1, -c[i][j + k - 1]);
                }
            }
            dp[i][j] = t[1] + s[i][j + k - 1] - s[i][j - 1] + s[i + 1][j + k - 1] - s[i + 1][j - 1];
            ans = max(ans, dp[i][j]);
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << ans;
    return 0;
}