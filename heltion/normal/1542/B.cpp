#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a == 1) {
            cout << ((n - 1) % b ? "No\n" : "Yes\n");
        }
        else {
            int ok = 0;
            for (LL i = 1; i <= n; i *= a)
                if ((n - i) % b == 0) ok = 1;
            cout << (ok ? "Yes\n" : "No\n");
        }
    }
    return 0;
}