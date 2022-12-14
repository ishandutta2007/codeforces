#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        if (b || c) s += '1';
        else s += '0';
        s += string(c, '1');
        s += string(a, '0');
        for (int i = 0; i < b; i++) s += '0' + (i & 1);
        cout << s << '\n';
    }

    return 0;
}