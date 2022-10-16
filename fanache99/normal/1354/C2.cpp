#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

const long double PI = acos(-1);
const int STEPS = 200;

long double f(long double angle1, long double angle2, long double r) {
    return max(max(r * cos(angle1), r * sin(angle1)), max(r * cos(angle2), r * sin(angle2)));
}

int main() {
    //ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        long double angle = 2 * PI / (4 * n);
        long double r = 1 / (2 * sin(angle));
        long double left = 0, right = angle;
        for (int step = 0; step < STEPS; step++) {
            long double middle1 = (2 * left + right) / 3, middle2 = (left + 2 * right) / 3;
            long double value1 = f(middle1, angle - middle1, r), value2 = f(middle2, angle - middle2, r);
            if (value1 < value2)
                right = middle2;
            else
                left = middle1;
        }
        cout << fixed << setprecision(12) << 2 * f(left, angle - left, r) <<  "\n";
    }
    return 0;
}