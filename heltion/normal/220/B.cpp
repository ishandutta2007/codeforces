#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
constexpr int B = 300;
int a[maxn], cnt[maxn];
int L[maxn], R[maxn];
int p[maxn], ans[maxn], sum;
void add(int x, int c){
    if(x >= maxn) return;
    if(cnt[x] == x) sum -= 1;
    cnt[x] += c;
    if(cnt[x] == x) sum += 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 0; i < m; i += 1){
        cin >> L[i] >> R[i];
        p[i] = i;
    }
    sort(p, p + m, [&](const int& x, const int& y){
        return make_pair(L[x] / B, R[x]) < make_pair(L[y] / B, R[y]);
    });
    int l = 1, r = 0;
    for(int i = 0; i < m; i += 1){
        while(r < R[p[i]]) add(a[r += 1], 1);
        while(l > L[p[i]]) add(a[l -= 1], 1);
        while(r > R[p[i]]) add(a[r --], -1);
        while(l < L[p[i]]) add(a[l ++], -1);
        ans[p[i]] = sum;
    }
    for(int i = 0; i < m; i += 1) cout << ans[i] << "\n";
    return 0;
}