#include <bits/stdc++.h>

using namespace std;


int a, b, x;


string rep_char(char c, int n) {
    string res = "";

    if (n > 0) {
        for (int i = 0; i < n; i++) {
            res += c;
        }
    }

    return res;
}

int main() {


    cin >> a >> b >> x;

    string ans = "";

    if (a > b) {
        for (int i = 0; i <= x; i++) {
            ans += to_string(i % 2);
            if (i % 2 == 0) {
                a--;
            } else {
                b--;
            }
        }
    } else {
        for (int i = 1; i <= x + 1; i++) {
            ans += to_string(i % 2);
            if (i % 2 == 0) {
                a--;
            } else {
                b--;
            }
        }
    }


    for (char c : ans) {
        cout << c;
        if (c == '0') {
            cout << rep_char(c, a);
            a = 0;
        } else {
            cout << rep_char(c, b);
            b = 0;
        }
    }
    cout << '\n';

    return 0;
}