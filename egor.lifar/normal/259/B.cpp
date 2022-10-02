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


int main(){
    //abc
    //def
    //ghk
    int a, b, c, d, e, f, g, h, k;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> k;
    for (int i = 1; i <= 100000; i++) {
        e = i;
        int s = b + e + h;
        a = s - d - g;
        k = s - g - h;
        if (e + a + k == s) {
            cout << a << ' ' << b << ' ' << c << endl;
            cout << d << ' ' << e << ' ' << f << endl;
            cout << g << ' ' << h << ' ' << k << endl;
            return 0;
        }
    }
    return 0;
}