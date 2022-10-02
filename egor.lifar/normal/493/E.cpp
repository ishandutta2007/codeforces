#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


long long t, a, b;


int main() {
    cin >> t >> a >> b;
    if (t == 1) {
        if (a == t && b == t) {
            cout << "inf" << endl;
            return 0;
        }
        if (a == 1) {
            cout << 0 << endl;
            return 0;
        }
        long long b1 = b;
        while (b % a == 0) {
            b /= a;
        }
        if (b == 1 && a <= b1) {
            cout << 1 << endl;
            return 0;
        }
    }
        if (t == a && t == b) {
            cout << 2 << endl;
            return 0;
        }
        if (a == b) {
            cout << 1 << endl;
            return 0;
        }
        if (a == 1) {
            cout << 0 << endl;
            return 0;
        }
        vector<long long> v;
        int t1 = 0;
        long long a1 = 1;
        while (b / a >= a1) {
            a1 *= a;
            t1++;
        }
        for (int i = t1; i >= 0; i--) {
            v.push_back(b / a1);
            b %= a1;
            a1 /= a;
        }
        reverse(v.begin(), v.end());
        a1 = 1;
        long long s = 0;
        for (int i = 0; i <= t1; i++) {
            s += v[i] * a1;
       //     cout << s << ' ' << v[i] << endl;
            a1 *= t;
        }
        cout << (s == a) << endl;
    return 0;
}