#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int n;
string s;


int main() {
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A' || s[i] == 'H' || s[i] == 'I' || s[i] == 'M' || s[i] == 'O' || s[i] == 'T' || s[i] == 'U' || s[i] == 'V' || s[i] == 'W' || s[i] == 'Y' || s[i] == 'X') {
            continue;
        }
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}