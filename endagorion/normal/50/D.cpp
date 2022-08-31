#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

#ifndef ONLINE_JUDGE

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);
FILE *file_in = fopen("input.txt", "rt");
FILE *file_out = fopen("output.txt", "wt");

#else

#define fin cin
#define fout cout
#define file_in stdin
#define file_out stdout

#endif

double dist(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int n, k, ieps;
    fin >> n >> k >> ieps;
    double eps = 0.001 * ieps;
    double x0, y0;
    fin >> x0 >> y0;
    vector< double > x(n), y(n);
    for (int i = 0; i < n; ++i) {
        fin >> x[i] >> y[i];
    }
    double l = 0.0, r = 1e9;
    while (r - l > 1e-9) {
        double m = 0.5 * (l + r);
        vector< double > probs(n);
        for (int i = 0; i < n; ++i) {
            probs[i] = min(1.0, exp(1 - dist(x0, y0, x[i], y[i]) / (m * m)));
        }
        vector< vector< double > > pkill(n + 1, vector< double >(n + 1, 0.0));
        pkill[0][0] = 1.0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                pkill[i + 1][j + 1] += pkill[i][j] * probs[i];
                pkill[i + 1][j] += pkill[i][j] * (1.0 - probs[i]);
            }
        }
        double fail = 0.0;
        for (int i = 0; i < k; ++i) {
            fail += pkill[n][i];
        }
        if (fail < eps) {
            r = m; 
        } else {
            l = m;
        }
    }

    fprintf(file_out, "%.10lf\n", l);
    return 0;
}