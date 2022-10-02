#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <unordered_map>


using namespace std;


const double Pi = acos(-1.0);
const double eps = 1e-12;
double h, w, a;


int main() {
    cin >> h >> w >> a;
    if (h > w) {
        swap(h, w);
    }
    if (a > 90.0) {
        a = 180 - a;
    }
    a = a * Pi / 180.0;
    double s = w / 2.0 - (h / 2.0) * tan(a / 2.0);
    double s1 = h / 2.0 - (w / 2.0) * tan(a / 2.0);
    if (s1 >= eps) {
        double k = h * w - tan(a) * (s * s + s1 * s1);
        printf("%.10lf\n", k);
    } else {
        double k = (h / 2.0 / sin(a / 2.0)) * (h / 2.0 / cos(a / 2.0)) * 2.0;
        printf("%.10lf\n", k);
    }
    return 0;
}