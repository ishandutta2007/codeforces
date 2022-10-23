#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> b(n);
    for (int& bi : b) cin >> bi;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) 
            cout << (i * j + n - i * i % n + b[i]) % n << " ";
        cout << "\n";
    }
}