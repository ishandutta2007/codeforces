#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2400;
constexpr int mod = 1000000007;
char s[maxn][maxn];
int R[maxn][maxn], D[maxn][maxn];
int ansR[maxn][maxn], ansD[maxn][maxn];
int sumR[maxn][maxn], sumD[maxn][maxn];
void add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
void addR(int i, int j, int n){
    for(int x = i; x <= n; x += x & -x) add(sumR[x][j], ansR[i][j]);
}
void addD(int i, int j, int m){
    for(int y = j; y <= m; y += y & -y) add(sumD[i][y], ansD[i][j]);
}
int SumR(int i, int j){
    int res = 0;
    for(int x = i; x; x -= x & -x) add(res, sumR[x][j]);
    return res;
}
int SumD(int i, int j){
    int res = 0;
    for(int y = j; y; y -= y & -y) add(res, sumD[i][y]);
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if(n == 1 and m == 1){
        cout << 1;
        return 0;
    }
    for(int i = 1; i <= n; i += 1) cin >> (s[i] + 1);
    for(int i = 1; i <= n; i += 1){
        int cnt = 0;
        for(int j = m; j; j -= 1){
            R[i][j] = m - cnt;
            if(s[i][j] == 'R') cnt += 1;
        }
    }
    for(int j = 1; j <= m; j += 1){
        int cnt = 0;
        for(int i = n; i; i -= 1){
            D[i][j] = n - cnt;
            if(s[i][j] == 'R') cnt += 1;
        }
    }
    for(int i = n; i; i -= 1)
        for(int j = m; j; j -= 1){
            if(i == n and j == m){
                ansR[i][j] = ansD[i][j] = 1;
                addR(i, j, n);
                addD(i, j, m);
            }
            else{
                ansR[i][j] = SumD(i, R[i][j]);
                ansD[i][j] = SumR(D[i][j], j);
                addR(i, j, n);
                addD(i, j, m);
            }
            //cout << i << " " << j << " " << ansR[i][j] << " " << ansD[i][j] << "\n";
        }
    cout << (ansR[1][1] + ansD[1][1]) % mod;
    return 0;
}