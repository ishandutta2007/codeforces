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

int field[600][600];
int N;

int f(int d, int n) {
    return field[d - n][n];
}

int main() {
	fout.precision(10);
	fout << fixed;

    fin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fin >> field[i][j];
        }
    }

    vector< vector<int> > sum(1, vector<int>(1, field[0][0]));
    for (int i = 1; i <= 2 * N - 2; ++i) {
        vector< vector<int> > newS(i + 1, vector<int>(i + 1, -1e9));
        for (int j = 0; j < i; ++j) {
            for (int k = j; k < i; ++k) {
                for (int d1 = 0; d1 < 2; ++d1) {
                    for (int d2 = 0; d2 < 2; ++d2) {
                        int jj = j + d1, kk = k + d2;
                        if (jj > kk) {
                            swap(jj, kk);
                        }
                        if (jj == kk) {
                            newS[jj][kk] = max(newS[jj][kk], sum[j][k] + f(i, jj));
                        } else {
                            newS[jj][kk] = max(newS[jj][kk], sum[j][k] + f(i, jj) + f(i, kk));
                        }
                    }
                }
            }
        }
        sum = newS;
    }

    fout << sum[N - 1][N - 1] << '\n';

	return 0;
}