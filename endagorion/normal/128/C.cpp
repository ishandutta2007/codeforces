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
    int n, m, k;
    fin >> n >> m >> k;
    int r = max(n, m);
    const long long P = 1000000007;
    vector< vector< long long > > ways(k + 1, vector< long long >(r + 1, 0));
    vector< vector< long long > > sums(k + 1, vector< long long >(r + 1, 0));
    vector< vector< long long > > sump(k + 1, vector< long long >(r + 1, 0));
    for (int i = 1; i <= r; ++i) {
        ways[0][i] = 1;
        sums[0][i] = i;
        sump[0][i] = sump[0][i - 1] + i;
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 2; j <= r; ++j) {
            ways[i][j] = ((j - 1) * sums[i - 1][j - 2] - sump[i - 1][j - 2] + P) % P;
            sums[i][j] = (sums[i][j - 1] + ways[i][j]) % P;
            sump[i][j] = (sump[i][j - 1] + j * ways[i][j]) %P ;
        }
    }

    long long ans = (ways[k][n] * ways[k][m]) % P;
    fout << ans << '\n';

    return 0;
}