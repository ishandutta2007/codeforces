#include <iostream>
#include <array>
#include <cmath>

void run(std::istream &in, std::ostream &out) {
    out.precision(5);
    out << std::fixed;
    std::array<int, 3> x;
    std::array<int, 3> y;
    std::array<int, 3> r;
    for (int i = 0; i < 3; i++) {
        in >> x[i] >> y[i] >> r[i];
    }
    double cXX = 2 * (x[0] - x[1]);
    double cXY = 2 * (y[0] - y[1]);
    double cXR = r[1] * r[1] - r[0] * r[0];
    double cXW = x[0] * x[0] + y[0] * y[0] - x[1] * x[1] - y[1] * y[1];
    double cYX = 2 * (x[1] - x[2]);
    double cYY = 2 * (y[1] - y[2]);
    double cYR = r[2] * r[2] - r[1] * r[1];
    double cYW = x[1] * x[1] + y[1] * y[1] - x[2] * x[2] - y[2] * y[2];
    double det = cXX * cYY - cYX * cXY;
    double cX1 = (cXR * cYY - cYR * cXY) / det;
    double cY1 = (cXX * cYR - cYX * cXR) / det;
    double cX2 = (cXW * cYY - cYW * cXY) / det;
    double cY2 = (cXX * cYW - cYX * cXW) / det;
    if (r[0] == r[1] && r[1] == r[2]) {
        out << cX2 << " " << cY2 << std::endl;
        return;
    }
    double c2 = cX1 * cX1 + cY1 * cY1;
    double c1 = 2 * cX1 * (cX2 - x[0]) + 2 * cY1 * (cY2 - y[0]) - r[0] * r[0];
    double c0 = (cX2 - x[0]) * (cX2 - x[0]) + (cY2 - y[0]) * (cY2 - y[0]);
    double d = c1 * c1 - 4 * c0 * c2;
    if (d < -1e-10) {
        return;
    }
    if (d < 1e-16) {
        double c = -c1 / 2 / c2;
        out << (cX1 * c + cX2) << " " << (cY1 * c + cY2) << std::endl;
        return;
    }
    double c_min = (-c1 - sqrt(d)) / 2 / c2;
    double c_max = (-c1 + sqrt(d)) / 2 / c2;
    if (c_max < 1) {
        return;
    }
    double c = c_min < 1 ? c_max : c_min;
    out << (cX1 * c + cX2) << " " << (cY1 * c + cY2) << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}