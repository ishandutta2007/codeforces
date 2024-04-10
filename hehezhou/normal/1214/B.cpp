#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, n, ans = 0;
    cin >> a >> b >> n;
    for(int i = 0; i <= n; i++) {
        if(i <= a && n - i <= b) ans++;
    }
    return cout << ans << endl, 0;
}