#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ans = 0;
        cin >> n;
        for (int i = 0, a; i < 2 * n; i += 1) {
            cin >> a;
            ans += a & 1;
        }
        if (ans == n) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}