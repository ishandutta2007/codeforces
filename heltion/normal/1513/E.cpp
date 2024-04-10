#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> inv(n + 1);
    for(int i = 1; i <= n; i += 1)
        inv[i] = i == 1 ? 1 : (mod - mod / i) * inv[mod % i] % mod;
    vector<int> a(n);
    LL sum = 0;
    for(int& x : a){
        cin >> x;
        sum += x;
    }
    if(sum % n){
        cout << "0\n";
        return 0;
    }
    int avg = sum / n, L = 0, M = 0, R = 0;
    for(int x : a){
        if(x < avg) L += 1;
        if(x == avg) M += 1;
        if(x > avg) R += 1;
    }
    map<int, int> mp;
    for(int x : a) mp[x] += 1;
    LL ans = 1;
    if(L <= 1 or R <= 1){
        for(int i = 1; i <= n; i += 1) ans = ans * i % mod;
        for(auto [x, y] : mp) for(int i = 1; i <= y; i += 1) ans = ans * inv[i] % mod;
        cout << ans << "\n";
        return 0;
    }
    for(int i = 1; i <= n; i += 1) ans = ans * i % mod;
    for(int i = 1; i <= M; i += 1) ans = ans * inv[i] % mod;
    for(int i = 1; i <= n - M; i += 1) ans = ans * inv[i] % mod;
    for(int i = 1; i <= L; i += 1) ans = ans * i % mod;
    for(int i = 1; i <= R; i += 1) ans = ans * i % mod;
    for(auto [x, y] : mp) if(x != avg) for(int i = 1; i <= y; i += 1) ans = ans * inv[i] % mod;
    cout << ans * 2 % mod;
    return 0;
}