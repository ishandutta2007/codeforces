#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void rmain() {
    cin >> s;
    if (s.back() != 'B') return cout << "NO\n", void();
    int cur = 0;
    for (auto i : s) {
        if (i == 'A') cur++;
        else cur--;
        if (cur < 0) return cout << "NO\n", void();
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) rmain();
}