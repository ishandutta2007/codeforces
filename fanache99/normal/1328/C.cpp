#include <iostream>
#include <string>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        string s, a, b;
        int n;
        cin >> n >> s;
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                a.append("0");
                b.append("0");
            }
            if (s[i] == '2')
                if (first) {
                    a.append("1");
                    b.append("1");
                }
                else {
                    a.append("0");
                    b.append("2");
                }
            if (s[i] == '1')
                if (first) {
                    a.append("1");
                    b.append("0");
                    first = false;
                }
                else {
                    a.append("0");
                    b.append("1");
                }
        }
        cout << a << "\n" << b << "\n";
    }
    return 0;
}