#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int cur = 0;
        bool flag = str.back() == 'B';
        for (char ch : str) {
            if (ch == 'A') cur++;
            else cur--;
            if (cur < 0) flag = 0;
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}