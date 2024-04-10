#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    int c0 = 0, c1 = 0;
    for (char c : s) {
        if (c == 'a') c0++;
        else c1++;
    }
    cout << c0 + min(c0 - 1, c1) << endl;
    return 0;
}