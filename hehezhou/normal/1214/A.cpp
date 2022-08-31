#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d, e, ans;
    cin >> n >> d >> e;
    e *= 5;
    ans = n;
    for(int i = 0; i < e; i++) {
        if(n < 0) break;
        ans = min(ans, n % e);
        n -= d;
    }
    return cout << ans << endl, 0;
}