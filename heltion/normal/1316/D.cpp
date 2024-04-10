#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000;
int n, cn;
int x[maxn + 1][maxn + 1], y[maxn + 1][maxn + 1], c[maxn + 1][maxn + 1];
int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};
int cnt[maxn * maxn + 1];
char ans[maxn + 1][maxn + 1];
char d[4] = {'D', 'U', 'R', 'L'};
set<pair<int, int>> s;
void no(){
    cout << "INVALID";
    exit(0);
}
bool check(int i, int j){
    return 1 <= i and i <= n and 1 <= j and j <= n;
}
void DFS(int i, int j){
    cnt[cn] += 1;
    for(int k = 0; k < 4; k += 1){
        int ni = i + di[k], nj = j + dj[k];
        if(not check(ni, nj)) continue;
        if(c[ni][nj]) continue;
        if(x[ni][nj] == x[i][j] and y[ni][nj] == y[i][j]){
            c[ni][nj] = c[i][j];
            DFS(ni, nj);
        }
    }
}
void DFS2(int i, int j){
    for(int k = 0; k < 4; k += 1){
        int ni = i + di[k], nj = j + dj[k];
        if(not check(ni, nj)) continue;
        if(ans[ni][nj]) continue;
        if(x[ni][nj] == x[i][j] and y[ni][nj] == y[i][j]){
            ans[ni][nj] = d[k];
            DFS2(ni, nj);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1) cin >> x[i][j] >> y[i][j];
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1)
            if(not c[i][j]){
                c[i][j] = cn += 1;
                DFS(i, j);
                if(x[i][j] != -1){
                    if(s.count({x[i][j], y[i][j]})) no();
                    if(c[x[i][j]][y[i][j]] != cn) no();
                }
                else if(cnt[cn] == 1) no();
            }
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1)
            if(x[i][j] == i and y[i][j] == j){
                ans[i][j] = 'X';
                DFS2(i, j);
            }
            else if(x[i][j] == -1 and not ans[i][j]){
                for(int k = 0; k < 4; k += 1){
                    int ni = i + di[k], nj = j + dj[k];
                    if(not check(ni, nj)) continue;
                    if(x[ni][nj] == x[i][j] and y[ni][nj] == y[i][j])
                        ans[i][j] = d[k ^ 1];
                }
                DFS2(i, j);
            }
    cout << "VALID\n";
    for(int i = 1; i <= n; i += 1) cout << (ans[i] + 1) << "\n";
    return 0;
}