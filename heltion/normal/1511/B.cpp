#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int a, b, c;
        cin >> a >> b >> c;
        for(int i = 0; i <= a - c; i += 1) cout << "1";
        for(int i = 1; i < c; i += 1) cout << "0";
        cout << " 1";
        for(int i = 1; i < b; i += 1) cout << "0";
        cout << "\n";
    }
    return 0;
}