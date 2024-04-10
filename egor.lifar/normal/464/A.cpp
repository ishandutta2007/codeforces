#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


int n;
string s;
int p;


int main() {
    cin >> n >> p;
    cin >> s;
    for (int i = n - 1; i >= 0; i--) {
        for (int k = 1; k < 26; k++) {
            if (s[i] - 'a' + k <= p - 1) {
                if (i - 2 >= 0 && char(s[i] + k) == s[i - 2]) {
                    continue;
                }
                if (i - 1 >= 0 && char(s[i] + k) == s[i - 1]) {
                    continue;
                }
                if ((n - i - 1 >= 3 && p < 3) || (k == 1 && p <= 2 && n - i - 1 == 2) || (k == 1 && i >= 1 && p == 1 && n - i - 1 == 1 && s[i - 1] == 'a') || (p == 1)) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    if (j < i) {
                        cout << s[j];
                    } else {
                        if (j == i) {
                            cout << char(s[j] + k);
                            s[j] = char(s[j] + k);
                        } else {
                            int s1 = 0;
                            while (char('a' + s1) == char(s[j - 1]) || (j >= 2 && char('a' + s1) == s[j - 2])) {
                                s1++;
                            }
                            cout << char('a' + s1);
                            s[j] = char('a' + s1);
                        }
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}