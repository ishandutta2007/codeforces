#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>


using namespace std;


#define eps 0.0000001
const double Pi = acos(-1);


int main() {
    double n, r, R;
    cin >> n >> R >> r;
    if (R < r) {
        cout << "NO" << endl;
        return 0;
    }
    if (abs(r - R) < eps || 2.0 * r > R + eps) {
        if (abs(n - 1) < eps) {
           cout << "YES" << endl;
        } else {
           cout << "NO" << endl;
        }
        return 0;
    }
    double g = R - r;
    double k = sqrt(g * g - r * r);
    if (n * acos(k / g) * 2.0 <= 2.0 * Pi + eps) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}