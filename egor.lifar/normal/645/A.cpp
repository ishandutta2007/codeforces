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


using namespace std;


string a, b, c, d;


int main() {
    cin >> a >> b >> c >> d;
    string s;
    s += a;
    s += b[1];
    s += b[0];
    string s1;
    s1 += c;
    s1 += d[1];
    s1 += d[0];
    string s2;
    string s3;
    for (int i = 0; i < 4; i++) {
        if (s[i] != 'X') {
            s2 += s[i];
        }
        if (s1[i] != 'X') {
            s3 += s1[i];
        }
    }
    for (int i = 0; i < 3; i++) {
        int k = i;
        bool bb = 1;
        for (int j = 0; j < 3; j++) {
            if (s2[k] != s3[j]) {
                bb = 0;
                break;
            }
            k++;
            k %= 3;
        }
        if (bb) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}