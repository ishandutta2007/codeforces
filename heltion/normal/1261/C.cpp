#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 4000000;
int n, m;
char s[maxn];
int k[maxn];
int sum[maxn];
char t[maxn];
int code(int i, int j){
    if(i < 1 or i > n or j < 1 or j > m) return 0;
    return (i - 1) * m + j + 1;
}
bool check(int T){
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1) sum[code(i, j)] = 0, t[code(i, j)] = '.';
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1) if(k[code(i, j)] >= 2 * T + 1){
            t[code(i + T, j + T)] = 'X';
            sum[code(i, j)] += 1;
            sum[code(i + 2 * T + 1, j)] -= 1;
            sum[code(i, j + 2 * T + 1)] -= 1;
            sum[code(i + 2 * T + 1, j + 2 * T + 1)] += 1;
        }
    sum[0] = 0;
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1)
            sum[code(i, j)] += sum[code(i, j - 1)];
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1)
            sum[code(i, j)] += sum[code(i - 1, j)];
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1)
            if(s[code(i, j)] == 'X' and not sum[code(i, j)]) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1) cin >> (s + code(i, 1));
    for(int i = n; i; i -= 1)
        for(int j = m; j; j -= 1){
            if(s[code(i, j)] == '.') k[code(i, j)] = 0;
            else k[code(i, j)] = min({k[code(i, j + 1)], k[code(i + 1, j)], k[code(i + 1, j + 1)]})  + 1;
        }
    int L = 0, R = 500;
    while(L < R){
        int M = (L + R + 1) >> 1;
        if(check(M)) L = M;
        else R = M - 1;
    }
    cout << L << "\n";
    check(L);
    for(int i = 1; i <= n; i += 1){
        for(int j = 1; j <= m; j += 1) cout << t[code(i, j)];
        cout << "\n";
    }
    return 0;
}