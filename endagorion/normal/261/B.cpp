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

int main() {
	fout.precision(10);
	fout << fixed;

    int N;
    fin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
    }
    int P;
    fin >> P;
    double ans = 0.0;
    for (int i = 0; i < N; ++i) {
        swap(a[i], a[N - 1]);
        vector< vector< vector<double> > > prob(N + 1, vector< vector<double> >(N + 1, vector<double>(51, 0.0)));
        prob[0][0][0] = 1.0;
        for (int j = 0; j < N - 1; ++j) {
            for (int k = 0; k <= j; ++k) {
                for (int s = 0; s <= 50; ++s) {
                    if (s + a[j] <= P) {
                        prob[j + 1][k + 1][s + a[j]] += prob[j][k][s] * (k + 1) / (j + 2);
                    }
                    prob[j + 1][k][s] += prob[j][k][s] * (j - k + 1) / (j + 2);
                }
            }
        }
        for (int k = 0; k < N; ++k) {
            for (int s = 0; s + a[N - 1] <= P; ++s) {
                ans += prob[N - 1][k][s];
            }
        }
        swap(a[i], a[N - 1]);
    }

    fout << ans << '\n';

	return 0;
}