#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

struct circle {
    double x, y;
    int r;
};

int main() {
    int n, r;
    cin >> n >> r;
    vector <int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    vector <circle> c(n);
    for (int i = 0; i < n; ++i) {
        double cur_y = r;
        for (int j = 0; j < i; ++j) {
            if (abs(x[i] - x[j]) > 2 * r) continue;
            double left = c[j].y;
            double right = 2e6 + 7;
            for (int s = 0; s < 100; ++s) {
                double y = (left + right) / 2.0;
                double k = sqrt(pow(x[i] - x[j],2) + pow(y - c[j].y,2));
                if (k < 2 * r) {
                    left = y;
                }
                else right = y;
            }
            double in = (left + right) / 2.0;
            cur_y = max(cur_y, in);
        }
        c[i].x = x[i];
        c[i].y = cur_y;
    }
    for (auto &e : c) {
        cout << fixed << setprecision(16) << e.y << " ";
    }
}