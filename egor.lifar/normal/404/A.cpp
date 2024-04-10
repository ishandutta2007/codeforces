#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>


using namespace std;


int n;
string s[1000];
bool t[1000][1000];
set<char> s1;

        
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    bool b = true;
    for (int j = 1; j < n; j++) {
        if (s[j][j] != s[j - 1][j - 1]) {
            b = false;
        }
        t[j][j] = true;
        t[j - 1][j - 1] = true;
    }
    for (int i = 1; i < n; i++) {
        if (s[i][n - 1 - i] != s[i - 1][n - i]) {
            b = false;
        }
        t[i][n - 1 - i] = true;
        t[i - 1][n - i] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!t[i][j]) {
                s1.insert(s[i][j]);
            }
        }
    }
    if (b && s1.size() == 1 && *s1.begin() != s[0][0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}