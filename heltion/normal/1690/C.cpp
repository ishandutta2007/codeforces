#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> s(n), f(n);
        for (int& si : s) cin >> si;
        for (int& fi : f) cin >> fi;
        for (int i = 0; i < n; i += 1)
            cout << f[i] - max(s[i], i ? f[i - 1] : 0) << " ";
        cout << "\n";
    }
    return 0;   
}