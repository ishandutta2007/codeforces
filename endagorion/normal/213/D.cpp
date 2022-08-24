#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

const double PI = 3.1415926535897932384626433832795;

int main() {
	fout.precision(10);
	fout << fixed;

    vector<double> x(5), y(5);
    double ang = 0.4 * PI;
    double r = sqrt(50.0 / (1 - cos(ang)));
    for (int i = 0; i < 5; ++i) {
        x[i] = r * cos(i * ang);
        y[i] = r * sin(i * ang);
    }
    double D = y[1] - y[4];

    int N;
    fin >> N;
    int M = 4 * N + 1;
    printf("%d\n", M);
    vector< vector<int> > edges(M + 1);
    for (int i = 0; i < N; ++i) {
        int k = i + 1;
        printf("%.10lf %.10lf\n", x[0], y[0] - i * D);
    }
    for (int i = 0; i < N + 1; ++i) {
        printf("%.10lf %.10lf\n", x[1], y[1] - i * D);
    }
    for (int i = 0; i < N; ++i) {
        printf("%.10lf %.10lf\n", x[2], y[2] - i * D);
        printf("%.10lf %.10lf\n", x[3], y[3] - i * D);
    }

    for (int i = 0; i < N; ++i) {
        printf("%d %d %d %d %d\n", i + 1, N + i + 1, 2 * N + 2 * i + 2, 2 * N + 2 * i + 3, N + i + 2);
    }

    for (int i = 0; i < N + 1; ++i) {
        printf("%d ", N + i + 1);
    }
    for (int i = N - 1; i >= 0; --i) {
        printf("%d %d %d %d ", 2 * N + 2 * i + 2, i + 1, 2 * N + 2 * i + 3, N + i + 1);
    }

	return 0;
}