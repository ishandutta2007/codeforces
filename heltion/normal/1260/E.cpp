#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int n, x, m;
    cin >> n;
    m = __builtin_ctz(n);
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        if(a[i] == -1) x = i;
    }
    int t = 0;
    while(x < (1 << (m - t))) t += 1;
    LL ans = 0;
    priority_queue<int, vector<int>, greater<int>> ms;
    int p = n;
    for(int i = 1; i <= t; i += 1){
        while(p >= (1 << (m - i + 1))) ms.push(a[p --]);
        ans += ms.top();
        ms.pop();
    }
    cout << ans;
    return 0;
}