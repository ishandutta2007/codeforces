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
    int a, b, n;
    fin >> a >> b >> n;
    for (int x = -1000; x <= 1000; ++x) {
        int A = a;
        for (int i = 0; i < n; ++i) {
            A *= x;
            if (abs(A) > abs(b)) {
                break;
            }
        }
        if (A == b) {
            fout << x << '\n';
            return 0;
        }
    }

    fout << "No solution\n";
    return 0;
}