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
    int N;
    fin >> N;
    vector< int > A(N);
    bool ones = true;
    for (int i = 0; i < N; ++i) {
        fin >> A[i];
        if (A[i] != 1) {
            ones = false;
        }
    }
    if (ones) {
        for (int i = 0; i < N - 1; ++i) {
            fout << "1 ";
        }
        fout << "2\n";
        return 0;
    }
    sort(A.begin(), A.end());
    fout << "1 ";
    for (int i = 0; i < N - 1; ++i) {
        fout << A[i] << ' ';
    }
    fout << '\n';

    return 0;
}