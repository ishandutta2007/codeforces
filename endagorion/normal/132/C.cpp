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

bool reach[101][101][101][2];

int main() {
    string s;
    fin >> s;
    int K;
    fin >> K;
    int N = s.length();
    for (size_t i = 0; i <= 100; ++i) {
        for (size_t j = 0; j <= 100; ++j) {
            for (size_t k = 0; k <= 100; ++k) {
                for (size_t l = 0; l < 2; ++l) {
                    reach[i][j][k][l] = false;
                }
            }
        }
    }

    reach[0][0][0][0] = reach[0][0][0][1] = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= i; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if (!reach[i][j][k][l]) {
                        continue;
                    }
                    for (size_t c = 0; c < 2; ++c) {
                        int ni = i + 1;
                        int nj = j + c;
                        bool move = (s[i] == 'T') ^ (c == 0);
                        int nk = k;
                        if (move) {                            
                            if (l == 0) {
                                ++nk;
                            } else {
                                --nk;
                            }
                        }
                        int nl = l;
                        if (!move) {
                            nl = 1 - l;
                        }
                        if (nk == -1) {
                            nk = 1;
                            nl = 1 - nl;
                        }
                        reach[ni][nj][nk][nl] = true;
                    }
                }
            }
        }
    }

    int res = -1;
    for (int j = K; j >= 0; j -= 2) {
        for (int k = 0; k <= N; ++k) {
            for (int l = 0; l < 2; ++l) {
                if (reach[N][j][k][l]) {
                    res = max(res, k);
                }
            }
        }
    }

    fout << res << '\n';
    return 0;
}