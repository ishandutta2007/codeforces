#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int& x : p) cin >> x;
        if (p[0] == n) {
            reverse(p.begin() + 1, p.end());
            for (int x : p) cout << x << " ";
            cout << "\n";
        }
        else if (p.back() == n) {
            reverse(p.begin(), p.begin() + n - 1);
            for (int x : p) cout << x << " ";
            cout << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}