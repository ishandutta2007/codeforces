#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


#define Pi acos(-1)
#define eps 0.0000001


double a[6];


int main() {
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    double s = 0.0;
    double t = sin(Pi * 2.0 / 3.0);
 //   cout << t << endl;
    if (t < 0) {
        t += 2.0 * Pi;
    }
    s += t * a[0] * a[5] * 0.5;
    s += t * a[1] * a[2] * 0.5;
    s += t * a[3] * a[4] * 0.5;
   // cout << t * a[3] * a[4] * 0.5 << endl;
    //cout << sin(2.0 * Pi) << endl;
    t = cos(Pi * 2.0 / 3.0);
  //  cout << t << endl;
    // if (t < 0) {
    //     t += 2.0 * Pi;
    // }
  //  cout << a[0] * a[0] + a[5] * a[5] - 2.0 * a[0] * a[5] * t << endl;
    double c = sqrt(a[0] * a[0] + a[5] * a[5] - 2.0 * a[0] * a[5] * t);
    double c1 = sqrt(a[1] * a[1] + a[2] * a[2] - 2.0 * a[1] * a[2] * t);
    double c2 = sqrt(a[3] * a[3] + a[4] * a[4] - 2.0 * a[3] * a[4] * t);
    double p = (c + c1 + c2) / 2.0;
    s +=  sqrt(p * (p - c) * (p - c1) * (p - c2));
  // cout << s << endl;
    double s1 = sqrt(1.5 * 0.5 * 0.5 * 0.5);
  //  cout << s1 << endl;
   // printf("%.6lf\n", s / s1);
    printf("%d\n", (int)(s / s1 + eps));
    return 0;
}