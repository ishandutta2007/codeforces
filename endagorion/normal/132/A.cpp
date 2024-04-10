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

int trans(int x) {
    int res = 0;
    for (int i = 0; i < 8; ++i) {
        res = 2 * res + x % 2;
        x /= 2;
    }
    return res;
}

int main() {
    char s[200];
    fin.getline(s, 200);
    int prev = 0;
    for (size_t i = 0; i < strlen(s); ++i) {
        int p;
        if (i == 0) {
            p = 0;
        } else {
            p = (int)s[i - 1];
        }
        int q = (int)s[i];
        fout << (trans(p) - trans(q) + 256) % 256 << '\n';
    }
    return 0;
}