#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n, m, p, x[100000], y[100000], x1, y1, z1;


int main() {
    cin >> n >> m >> x1 >> y1 >> z1 >> p;
    for (int i = 0; i < p; i++) {
        cin >> y[i] >> x[i];
    }
    x1 %= 4;
    y1 %= 2;
    z1 %= 4;
    for (int j = 0; j < x1; j++) {
        for (int i = 0; i < p; i++) {
            int k = y[i];
            y[i] = x[i];
            x[i] = n - k + 1;
        }
        swap(n, m);
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < y1; j++) {
            x[i] = m - x[i] + 1;
        }
    }
    for (int j = 0; j < z1; j++) {
        for (int i = 0; i < p; i++) {
            int k = x[i];
            x[i] = y[i];
            y[i] = m - k + 1;
        }
        swap(n, m);
    }
    for (int i = 0; i < p; i++) {
        cout << y[i] << ' ' << x[i] << endl;
    }
    return 0;
}