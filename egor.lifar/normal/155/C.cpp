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
int k;
string a[26];
bool b[100000];


int main() {
    cin >> s >> k;
    n = s.size();
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for (int i = k; i < 2 * k; i++) {
        a[i]+= a[i - k][1];
        a[i]+= a[i - k][0];
    }
    int ans = 0;
    for (int j = 0; j < 2 * k; j++) {
        n = s.size();
        for (int i = 0; i < n; i++) {
            b[i] = false;
        }
        int k = 0;
        while (k < n) {
            int k1 = k;
            while (k < n) {
                if (s[k] == a[j][0] || s[k] == a[j][1]) {
                    k++;
                } else {
                    break;
                }
            }
            int c = 0, d = 0;
            for (int t = k1; t < k; t++) {
                if (s[t] == a[j][0]) {
                    c++;
                } else {
                    d++;
                }
            }
            if (c < d) {
                for (int t = k1; t < k; t++) {
                    if (s[t] == a[j][0]) {
                        b[t] = true;
                        ans++;
                    }
                }
            } else {
                for (int t = k1; t < k; t++) {
                    if (s[t] == a[j][1]) {
                        b[t] = true;
                        ans++;
                    }
                }
            }
            while (k < n && s[k] != a[j][0] && s[k] != a[j][1]) {
                k++;
            }
        }
        string s1;
        for (int i = 0; i < n; i++) {
            if (!b[i]) {
                s1 += s[i];
            }
        }
        s = s1;
    }
    cout << ans << endl;
    return 0;
}