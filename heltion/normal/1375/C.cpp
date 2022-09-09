#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 1;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    for(cin >> t; t; t -= 1){
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        cout << (a[1] < a[n] ? "YES\n" : "NO\n");
    }
    return 0;
}