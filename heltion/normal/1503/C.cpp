#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
LL a[maxn], b[maxn], c[maxn];
int p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    LL ans = 0;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i] >> c[i];
        b[i] = a[i] + c[i];
        ans += c[i];
        p[i] = i;
    }
    sort(p + 1, p + n + 1, [&](const int& x, const int& y){
        return a[x] < a[y];
    });
    LL x = b[p[1]];
    for(int i = 2; i <= n; i += 1){
        int j = p[i];
        ans += max(a[j] - x, 0LL);
        x = max(b[j], x);
    }
    cout << ans;
    return 0;
}