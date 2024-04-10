#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
constexpr int maxn = 200000;
int a[maxn + 1], Log[maxn + 1];
int rmq[maxn + 1][18];
int mini(int i, int j){
    if(a[i] < a[j] or (a[i] == a[j] and i < j)) return i;
    return j;
}
int fmin(int L, int R){
    int j = Log[R - L + 1];
    return mini(rmq[L][j], rmq[R - (1 << j) + 1][j]);
}
int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, p;
        cin >> n >> p;
        for(int i = 2; i <= n; i += 1) Log[i] = Log[i >> 1] + 1;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        for(int j = 0; j <= Log[n]; j += 1)
            for(int i = 1; i + (1 << j) - 1 <= n; i += 1)
                if(j == 0) rmq[i][j] = i;
                else rmq[i][j] = mini(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        LL ans = (LL)p * (n - 1);
        function<void(int ,int)> DFS = [&](int L, int R){
            if(L >= R) return;
            int m = fmin(L, R);
            if(a[m] >= p) return;
            int l = m, r = m;
            while(l - 1 >= L and a[l - 1] % a[m] == 0) l -= 1;
            while(r + 1 <= R and a[r + 1] % a[m] == 0) r += 1;
            ans -= (LL)(r - l) * (p - a[m]);
            DFS(L, min(l, m - 1));
            DFS(max(r, m + 1), R);
        };
        DFS(1, n);
        cout << ans << "\n";
    }
    return 0;
}