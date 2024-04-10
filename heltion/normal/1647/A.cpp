#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        if (n % 3 == 1) {
            cout << "1";
            for (int i = 0; i < n / 3; i += 1) cout << "21";
        }
        else if (n % 3 == 2) {
            cout << "2";
            for (int i = 0; i < n / 3; i += 1) cout << "12";
        }
        else {
            for (int i = 0; i < n / 3; i += 1) cout << "21";
        }
        cout << "\n";
    }
    return 0;
}