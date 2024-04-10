#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 1;
LL h[maxn], b[maxn];
int rmq[maxn][19];
int Log[maxn];
int mini(int i, int j){
    return h[i] < h[j] ? i : j;
}
int fm(int L, int R){
    int j = Log[R - L + 1];
    return mini(rmq[L][j], rmq[R - (1 << j) + 1][j]);
}
LL DFS(int L, int R, int l, int r){
    if(L > R) return 0;
    int M = fm(L, R);
    LL ret = 0;
    if(l == 0 and r == 0){
        ret = b[M];
        ret += DFS(L, M - 1, 0, 1);
        ret += DFS(M + 1, R, 1, 0);
    }
    if(l == 0 and r){
        ret = DFS(L, M - 1, 0, 1);
        ret += max(b[M] + DFS(M + 1, R, 1, 1), 0LL);
    }
    if(l and r == 0){
        ret = DFS(M + 1, R, 1, 0);
        ret += max(b[M] + DFS(L, M - 1, 1, 1), 0LL);
    }
    if(l and r){
        LL vL = DFS(L, M - 1, 1, 1);
        LL vR = DFS(M + 1, R, 1, 1);
        ret = max({b[M] + vL + vR, vL, vR});
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> h[i];
    for(int i = 2; i <= n; i += 1) Log[i] = Log[i >> 1] + 1;
    for(int j = 0; j < 19; j += 1){
        for(int i = 1; i + (1 << j) - 1 <= n; i += 1){
            if(j == 0) rmq[i][j] = i;
            else rmq[i][j] = mini(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int i = 1; i <= n; i += 1) cin >> b[i];
    cout << DFS(1, n, 0, 0);
    return 0;
}