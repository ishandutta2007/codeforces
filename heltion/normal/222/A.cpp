#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; i += 1) if(a[i] != a[k]) ans = i;
    cout << (ans >= k ? -1 : ans);
    return 0;
}