#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>


using namespace std;


int n;
int l = -1000000001, r = 1000000001;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a;
        cin >> a;
        string s1;
        cin >> s1;
        if (s == "<") {
            if (s1 == "Y") {
                r = min(r, a - 1);
            } else {
                l = max(a, l);
            }
        }
        if (s == ">") {
            if (s1 == "Y") {
                l = max(a + 1, l);
            } else {
                r = min(a, r);
            }
        }
        if (s == ">=") {
            if (s1 == "Y") {
                l = max(a, l);
            } else {
                r = min(a - 1, r);
            }
        }
        if (s == "<=") {
            if (s1 == "Y") {
                r = min(a, r);
            } else {
                l = max(a + 1, l);
            }
        }
    }
    if (l > r) {
        cout << "Impossible" << endl;
    } else {
        cout << r << endl;
    }
    return 0;
}