#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        int x = 0;
        for (int i = 30; i >= 0; i -= 1) {
            if (((x ^ n) | ((1 << i) - 1)) <= m) x |= 1 << i;
        }
        cout << x << "\n";
    }
    return 0;
}