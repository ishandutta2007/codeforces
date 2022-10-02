#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <bitset>
#include <unordered_map>


using namespace std;


int n, t;
string s;


int main () {
    cin >> n >> t;
    cin >> s;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            l = i;
            break;
        }
    }   
    l++;
    int tt = l - 1;
    for (int i = l; i < n; i++) {
        tt = max(tt, i - 1);
        while (s[tt + 1] == '4') {
            tt++;
        }
        if (s[i] >= '5') {
            for (int j = i; j < n; j++) {
                s[j] = '0';
            }
            s[(i - 1 == l - 1 ? i - 2: i - 1)]++;
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == '.') {
                    continue;
                }
                if (s[j] > '9') {
                    s[j] -= 10;
                   // cout << s[j] << endl;
                    if (j == 0) {
                        string s1;
                        s1 += '1';
                        s1 += s;
                        s = s1;
                    } else {
                        s[(j - 1 == l - 1 ? j - 2: j - 1)]++;
                    }
                }
            }
            break;
        } else {
            if (s[i] < '4') {
                continue;
            } else {
              //  cout << tt - i + 2 << endl;
                if (tt - i + 1 + 1 <= t && tt != n - 1 && s[tt + 1] >= '5') {
                   // cout << "opa" << endl;
                    for (int j = i; j < n; j++) {
                        s[j] = '0';
                    }
                    s[(i - 1 == l - 1 ? i - 2: i - 1)]++;
                    for (int j = i - 1; j >= 0; j--) {
                        if (s[j] == '.') {
                            continue;
                        }
                        if (s[j] > '9') {
                            s[j] -= 10;
                            if (j == 0) {
                                string s1;
                                s1 += '1';
                                s1 += s;
                                s = s1;
                            } else {
                                s[(j - 1 == l - 1 ? j - 2: j - 1)]++;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
   // cout << s << endl;
    int ll = n - 1;
    while (s[ll] == '0') {
        ll--;
    }
    if (s[ll] == '.') {
        ll--;
    }
    for (int i = 0; i <= ll; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}