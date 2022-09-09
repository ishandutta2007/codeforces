#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
#define code(i, j) m * (i - 1) + j
int a[maxn], b[maxn], v[maxn], n, m, ans;
void fuck(int c){
    fill(v, v + n, 0);
    for(int i = 1; i <= n; i += 1)
        if(a[code(i, c)] % m == c % m and a[code(i, c)] <= n * m)
            v[(i - (a[code(i, c)] + m - 1) / m + n) % n] += 1;
    int pans = n;
    for(int i = 0; i < n; i += 1) pans = min(pans, i + n - v[i]);
    ans += pans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1) cin >> a[code(i, j)];
    for(int i = 1; i <= m; i += 1) fuck(i);
    cout << ans;
    return 0;
}