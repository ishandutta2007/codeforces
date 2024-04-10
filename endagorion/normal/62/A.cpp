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

bool comp(int a, int b) {
    return b >= a - 1 && b <= 2 * (a + 1);
}

int main() {
    int al, ar, bl, br;
    fin >> al >> ar >> bl >> br;

    if (comp(al, br) || comp(ar, bl)) {
        fout << "YES\n";
    } else {
        fout << "NO\n";
    }

    return 0;
}