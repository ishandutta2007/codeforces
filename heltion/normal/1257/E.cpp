#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int L[maxn], R[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k1, k2, k3, n;
    cin >> k1 >> k2 >> k3;
    n = k1 + k2 + k3;
    for(int i = 1, a; i <= k1; i += 1){
        cin >> a;
        L[1] += 1;
        L[a + 1] -= 1;
    }
    for(int i = 1, a; i <= k2; i += 1){
        cin >> a;
        L[a + 1] += 1;
        L[n + 2] -= 1;
        R[1] += 1;
        R[a + 1] -= 1;
    }
    for(int i = 1, a; i <= k3; i += 1){
        cin >> a;
        R[a + 1] += 1;
        R[n + 2] -= 1;
    }
    for(int i = 1; i <= n + 1; i += 1){
        L[i] += L[i - 1];
        R[i] += R[i - 1];
    }
    int m = n, ans = n;
    for(int i = 1; i <= n + 1; i += 1){
        m = min(m, L[i]);
        ans = min(ans, m + R[i]);
    }
    cout << ans;
    return 0;
}