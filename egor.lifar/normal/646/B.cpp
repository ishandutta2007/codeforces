#include <iostream>
#include <sstream>
#include <cstdio>
#include <string.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;




int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n - 1; i++) {
        int k = i + 1;
        bool b = 1;
        if (n - k >= k) {
            continue;
        }
        for (int j = n - k; j < n; j++) {
            if (s[j] != s[j - n + k]) {
                b = 0;
                break;
            }
        }
        if (b) {
            cout << "YES" << endl;
            for (int g = 0; g <= i; g++) {
                cout << s[g];
            }
            cout << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}