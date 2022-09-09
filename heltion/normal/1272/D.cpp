#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int L[maxn], R[maxn], a[maxn];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 1; i <= n; i += 1)
        if(a[i] > a[i - 1]) L[i] = L[i - 1] + 1;
        else L[i] = 1;
    for(int i = n; i; i -= 1)
        if(a[i] < a[i + 1]) R[i] = R[i + 1] + 1;
        else R[i] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i += 1) ans = max(ans, L[i]);
    for(int i = 2; i < n; i += 1) if(a[i - 1] < a[i + 1]) ans = max(ans, L[i - 1] + R[i + 1]);
    cout << ans;
}