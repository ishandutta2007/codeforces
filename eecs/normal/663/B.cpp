#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int n = atoi(str.substr(4).c_str());
        int m = str.size() - 5, pw = 10, f = 1989;
        while (m--) f += pw, pw *= 10;
        while (n < f) n += pw;
        cout << n << endl;
    }
    return 0;
}