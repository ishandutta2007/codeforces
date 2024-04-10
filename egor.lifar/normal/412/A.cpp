#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n, k;
string s;


int main() {
    cin >> n >> k;
    cin >> s;
    if (2 * n - k - 1 <= n + k - 2) {
        for (int i = k; i <= n; i++) {
            cout << "PRINT " << s[i - 1] << endl;
            if (i != n) {
                cout << "RIGHT" << endl;
            }
        }
        for (int i = n; i >= k; i--) {
            if (i == 1) {
                continue;
            }
            cout << "LEFT" << endl;
        }
        for (int i = k - 1; i >= 1; i--) {
            cout << "PRINT " << s[i - 1] << endl;
            if (i != 1) {
                cout << "LEFT" << endl;
            }
        }
    } else {
        for (int i = k; i >= 1; i--) {
            cout << "PRINT " << s[i - 1] << endl;
            if (i != 1) {
                cout << "LEFT" << endl;
            }
        }
        for (int i = 1; i < k; i++) {
            if (i == n) {
                continue;
            }
            cout << "RIGHT" << endl;
        }
        for (int i = k; i < n; i++) {
            cout << "RIGHT" << endl;
            cout << "PRINT " << s[i] << endl;
        }
    }
    return 0;
}