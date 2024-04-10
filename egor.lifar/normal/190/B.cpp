#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>    


using namespace std;


double x[2], y[2], r[2];


int main() {
    for (int i = 0; i < 2; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    double s = abs(sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1])) - r[0] - r[1]);
    double s1 = abs(sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1])) - r[0] + r[1]);
    double s2 = abs(sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1])) - r[1] + r[0]);
   // cout << sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1])) << endl;
   // cout << s << endl;
    if (sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1])) < r[0] + r[1] && r[0] <= sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1])) && r[1] <= sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]))) {
        cout << 0 << endl;
        return 0;
    }
    if (min(s2 / 2.00, min(s1 / 2.00, s / 2.0)) >= 0.1 && min(s2 / 2.00, min(s1 / 2.00, s / 2.0)) < 0.2) {
        cout << 0 << endl;
        return 0;
    }
    printf("%.10lf\n", min(s2 / 2.00, min(s1 / 2.00, s / 2.0)));
    return 0;
}