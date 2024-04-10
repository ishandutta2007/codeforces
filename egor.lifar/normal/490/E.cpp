#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>  
#include <queue>  


using namespace std;


int n;
string s[100000];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            for (int j = 0; j < (int)s[i].size(); j++) {
                if (s[i][j] == '?') {
                    if (j == 0) {
                        s[i][j] = '1';
                    } else {
                        s[i][j] = '0';
                    }
                }
            }
            continue;
        }
        if ((int)s[i].size() < (int)s[i - 1].size()) {
            cout << "NO" << endl;
            return 0;
        }
        if ((int)s[i].size() > (int)s[i - 1].size()) {
            for (int j = 0; j < (int)s[i].size(); j++) {
                if (s[i][j] == '?') {
                    if (j == 0) {
                        s[i][j] = '1';
                    } else {
                        s[i][j] = '0';
                    }
                }
            }
            continue;
        }
        string a;
        for (int j = 0; j < (int)s[i].size(); j++) {
                if (s[i - 1][j] != '9') {
                    string s1 = s[i];
                    if (s[i][j] == '?') {
                        s1[j] = s[i - 1][j] + 1;
                    }
                    for (int g = 0; g < (int)s1.size(); g++) {
                        if (g < j) {
                            if (s1[g] == '?') {
                                s1[g] = s[i - 1][g];
                            }
                        } else {
                            if (g > j) {
                                if (s1[g] == '?') {
                                    s1[g] = '0';
                                }
                            }
                        }
                    }
                    if (s1 > s[i - 1]) {
                        if ((int)a.size() < (int)s1.size()) {
                            a = s1;
                        } else {
                            a = min(a, s1);
                        }
                    }
                }
        }
        s[i] = a;
        if (s[i] < s[i - 1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}