#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int t;


int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;
        if (n % 3LL != 0LL) {
            cout << "no" << endl;
            continue;
        }
        bool b = true;
        for (int j = 0; j < 2 && b; j++) {
            for (int g = 0; g < 2; g++) {
                long long f = d1, f1 = d2;
                if (j == 1) {
                    f *= -1LL;
                }
                if (g == 1) {
                    f1 *= -1LL;
                }
                if (k >= f * 2LL + f1 && (k - f * 2LL - f1) % 3LL == 0LL) {
                    long long s = (k - f * 2LL - f1) / 3LL;
                    long long s1 = s;
                    s = max(s, s1 + f);
                    s = max(s, s1 + f + f1);
                   // cout << s << ' ' << s1 << endl;
                    if (s1 + f >= 0 && s1 + f + f1 >= 0 && s1 >= 0 && n >= (s - s1) + (s - s1 - f) + (s - s1 - f - f1) + k && (n - (s - s1) - (s - s1 - f) - (s - s1 - f - f1) - k) % 3LL == 0LL) {
                        cout << "yes" << endl;
                        b = false;
                        break;
                    }
                }
            }
        }
        if (b) {
            cout << "no" << endl;
        }
    }
    return 0;
}