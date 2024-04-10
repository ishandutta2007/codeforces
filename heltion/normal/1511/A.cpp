#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, ans = 0;
        cin >> n;
        for(int i = 0, type; i < n; i += 1){
            cin >> type;
            ans += type != 2;
        }
        cout << ans << "\n";
    }
    return 0;
}