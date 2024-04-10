#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x : a) cin >> x;
        sort(a.begin(), a.end(), [](const int& x, const int& y){
            return x % 2 < y % 2;
        });
        int ans = 0;
        for(int i = 0; i < n; i += 1)
            for(int j = i + 1; j < n; j += 1)
                ans += gcd(a[i], a[j] * 2) > 1;
        cout << ans << "\n";
    }
    return 0;
}