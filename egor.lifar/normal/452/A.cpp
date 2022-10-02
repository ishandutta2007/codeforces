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
string a[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};


int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < 8; i++) {
        if (a[i].size() == n) {
            bool b = true;
            for (int j = 0; j < n; j++) {
                if (s[j] != a[i][j] && s[j] != '.') {
                    b = false;
                    break;
                }
            }
            if (b) {
                cout << a[i] << endl;
                return 0;
            }
        }
    }
    return 0;
}