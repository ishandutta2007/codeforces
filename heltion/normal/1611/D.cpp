#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> b(n), p(n), w(n), q(n);
        for (int& x : b) {
            cin >> x;
            x -= 1;
        }
        for (int& x : p) {
            cin >> x;
            x -= 1;
        }
        for (int i = 0; i < n; i += 1) q[p[i]] = i;
        int ok = 1;
        for (int i = 0; i < n; i += 1)
            if (b[i] != i) {
                w[i] = q[i] - q[b[i]];
                if (w[i] < 0) ok = 0;
            }
        if (ok) for (int x : w) cout << x << " ";
        else cout << "-1";
        cout << "\n";  
    }
    return 0;
}