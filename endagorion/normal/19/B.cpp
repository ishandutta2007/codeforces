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

int main() {
    int n;
    fin >> n;
    vector< int > t(n);
    vector< long long > c(n);
    for (int i = 0; i < n; ++i) {
        fin >> t[i] >> c[i];
    }
    vector< vector< long long > > minCost(n + 1, vector< long long >(2 * n + 1, 1e15));
    minCost[0][n] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 2 * n; ++j) {
            minCost[i + 1][min(j + t[i], 2 * n)] = min(minCost[i + 1][min(j + t[i], 2 * n)], minCost[i][j] + c[i]);
            if (j > 0) {
                minCost[i + 1][j - 1] = min(minCost[i + 1][j - 1], minCost[i][j]);
            }
        }
    }
    long long ans = 1e15;
    for (int i = n; i <= 2 * n; ++i) {
        ans = min(ans, minCost[n][i]);
    }
    fout << ans << '\n';

    return 0;
}