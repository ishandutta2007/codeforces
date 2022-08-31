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


fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

int minw[201][40001][2];

int main() {
	fout.precision(10);
	fout << fixed;

    int N, A, B;
    fin >> N >> A >> B;
    vector<int> l(N), s(N + 1);
    s[0] = 0;
    for (int i = 0; i < N; ++i) {
        fin >> l[i];
        s[i + 1] = s[i] + l[i];
    }
    for (int i = 0; i <= 200; ++i) {
        for (int j = 0; j <= 40000; ++j) {
            for (int k = 0; k < 2; ++k) {
                minw[i][j][k] = 1e9;
            }
        }
    }
    minw[1][l[0]][0] = minw[1][0][1] = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= 40000; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (j > A || s[i] - j > B) {
                    minw[i][j][k] = 1e9;
                }
                if (minw[i][j][k] >= 1e9) {
                    continue;
                }
                for (int kk = 0; kk < 2; ++kk) {
                    minw[i + 1][j + (kk == 0 ? l[i] : 0)][kk] =
                        min(minw[i + 1][j + (kk == 0 ? l[i] : 0)][kk], minw[i][j][k] + (k != kk ? min(l[i], l[i - 1]) : 0));
                }
            }
        }
    }

    int ans = 1e9;
    for (int j = 0; j <= 40000; ++j) {
        for (int k = 0; k < 2; ++k) {
            if (j > A || s[N] - j > B) {
                continue;
            }
            ans = min(ans, minw[N][j][k]);
        }
    }

    fout << (ans >= 1e9 ? -1 : ans) << '\n';

	return 0;
}