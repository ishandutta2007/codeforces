#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int a[maxn], c[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        int k = 1;
        for(int i = 1; i <= n; i += 1) c[i] = 0;
        c[a[1]] += 1;
        c[a[n]] += 1;
        for(int i = 1; i < n; i += 1)
            if(a[i] == a[i + 1]){
                k += 1;
                c[a[i]] += 2;
            }
        int m = max_element(c + 1, c + n + 1) - c, f = 0;
        for(int i = 1; i < n; i += 1)
            if(a[i] != a[i + 1] and a[i] != m and a[i + 1] != m) f += 1;
        if(c[m] <= k + 1) cout << k - 1 << "\n";
        else if(c[m] - k - 1 > f) cout << "-1\n";
        else cout << c[m] - 2 << "\n";
    }
    return 0;
}