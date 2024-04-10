#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
constexpr LL mod = 1'000'000'007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    LL A = 1, B = 1;
    for(int i = 1; i <= n; i += 1) A = A * i % mod;
    for(int i = 1; i < n; i += 1) B = B * 2 % mod;
    cout << (A + mod - B) % mod;
    return 0;
}