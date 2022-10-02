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


int kk, x, n, m;
string s;


void getans(char c, int l, char c1, char c2, int l1, char c3) {
   // cout << l << ' ' << l1 << endl;
    string a, b;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; i++) {
        a[i] = 'B';
    }
    for (int i = 0; i < m; i++) {
        b[i] = 'B';
    }
    a[0] = c;
    a[n - 1] = c1;
    b[0] = c2;
    b[m - 1] = c3;
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] == 'A' && l > 0 && a[i] == 'B') {
            a[i] = 'C';
            l--;
        }
        if (l > 0 && a[i] == 'B' && a[i + 1] == 'C') {
            a[i] = 'A';
            l--;
        }
        if (a[i] == 'B' && a[i + 1] == 'B' && l > 0) {
            a[i] = 'A';
            a[i + 1] = 'C';
            l--;
        }
    }
    for (int i = 1; i < m - 1; i++) {
        if (b[i - 1] == 'A' && l > 0 && b[i] == 'B') {
            b[i] = 'C';
            l1--;
        }
        if (l > 0 && b[i] == 'B' && b[i + 1] == 'C') {
            b[i] = 'A';
            l1--;
        }
        if (b[i] == 'B' && b[i + 1] == 'B' && l1 > 0) {
            b[i] = 'A';
            b[i + 1] = 'C';
            l1--;
        }
    }
    if (n == 2 && a == "AC") {
        l--;
    }
    if (m == 2 && b == "AC") {
        l1--;
    }
   // cout << c << ' ' << c1 << endl;
    //cout << a << endl;
    //cout << b << endl;
    //cout << endl;
    if (l == 0 && l1 == 0) {
        //cout << l << ' ' << l1 << endl;
        //cout << c2 << endl;
      //  cout << l2 << ' ' << l3 << endl;
        cout << a << endl;
        cout << b << endl;
        exit(0);
    }
}


int main(){
    cin >> kk >> x >> n >> m;
    s = "ABC";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int g = 0; g < 3; g++) {
                    for (int t = 0; t <= n / 2; t++) {
                        for (int t1 = 0; t1 <= m / 2; t1++) {
                            if (n == 1 && i != j) {
                                continue;
                            }
                            if (m == 1 && k != g) {
                                continue;
                            }
                            if (kk == 1 && x == t) {
                                getans(s[i], t, s[j], s[k], t1, s[g]);
                            }
                            if (kk == 2 && x == t1) {
                                getans(s[i], t, s[j], s[k], t1, s[g]);
                            }
                            int i1 = i, j1 = j, k1 = k, g1 = g;
                            long long tt = t, tt1 = t1;
                            for (int l = 3; l <= kk; l++) {
                                int c = 0;
                                if (j1 == 0 && k1 == 2) {
                                    c = 1;
                                }
                                int i2 = i1;
                                i1 = k1;
                                j1 = g1;
                                int tt2 = tt;
                                tt = tt1;
                                tt1 = tt2 + tt1 + c;
                                k1 = i2;
                            } 
                           // cout << tt1 << endl;
                            if (tt1 == x) {
                               // cout << "opa" << endl;
                                getans(s[i], t, s[j], s[k], t1, s[g]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Happy new year!" << endl;
    return 0;
}