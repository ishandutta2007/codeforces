#include <bits/stdc++.h>
using namespace std;
int n;
void rmain() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum ^= x - 1;
    }
    cout << (sum % 2 ? "errorgorn" : "maomao90") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) rmain();
}