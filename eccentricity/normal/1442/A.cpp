#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000;
LL a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        a[n + 1] = 0;
        for(int i = n + 1; i >= 1; i -= 1) a[i] -= a[i - 1];
        LL x = a[1], y = - a[n + 1];
        LL pe = 0, ne = 0;
        for(int i = 2; i <= n; i += 1){
            if(a[i] > 0) pe += a[i];
            else ne -= a[i];
        }
        if(x < ne or y < pe) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}