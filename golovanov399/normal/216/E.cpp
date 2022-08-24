#include <bits/stdc++.h>

using namespace std;

int main() {
    
    cin.sync_with_stdio(0);
    int k, b, n;
    cin >> k >> b >> n;
    
    if (b == 0) {
        long long ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                cur += 1;
            } else {
                cur = 0;
            }
            ans += cur;
        }
        cout << ans << "\n";
        return 0;
    }
    
    map<int, int> M;
    M[0] = 1;
    long long ans = 0;
    int cur = 0;
    int longest0 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cur = (cur + x) % (k - 1);
        int look = (cur - b + k - 1) % (k - 1);
        ans += M[look];
        M[cur] += 1;
        if (x == 0) {
            longest0 += 1;
        } else {
            longest0 = 0;
        }
        if (b == k - 1) {
            ans -= longest0;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}