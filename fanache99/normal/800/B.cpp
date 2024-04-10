//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000;
const double INF = 4000000000;

struct Point {
    double x;
    double y;
};

Point v[1 + MAXN + 1];

double Distance(double x1, double y1, double x2, double y2, double x0, double y0) {
    return fabs((y2 - y1) * x0 - (x2 - x1) * y0 + x2 * y1 - y2 * x1) / sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i].x >> v[i].y;
    v[0] = v[n];
    v[n + 1] = v[1];
    double answer = INF;
    for (int i = 1; i <= n; i++)
        answer = min(answer, Distance(v[i - 1].x, v[i - 1].y, v[i + 1].x, v[i + 1].y, v[i].x, v[i].y) * 0.5);
    cout << fixed << setprecision(10) << answer << "\n";
    return 0;
}