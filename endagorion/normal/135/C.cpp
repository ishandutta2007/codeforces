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
    string s;
    fin >> s;
    int N = s.length();
    int zeros = 0, ones = 0, qs = 0;
    for (int i = 0; i < N; ++i) {
        switch (s[i]) {
            case '0': {
                ++zeros;
                break;
                      }
            case '1': {
                ++ones;
                break;
                      }
            case '?': {
                ++qs;
                break;
                      }                      
        }
    }
    bool f00, f01, f10, f11;
    f00 = f01 = f10 = f11 = false;
    int moves0 = (N + 1) / 2 - 1;
    int moves1 = N / 2 - 1;

    f00 = (moves0 >= ones);
    f11 = (moves1 >= zeros);

    if (ones + qs > moves0 && zeros + qs > moves1) {
        if (s[N - 1] != '?') {
            if (s[N - 1] == '0') {
                f10 = true;
            } else {
                f01 = true;
            }
        } else {
            ++ones;
            --qs;
            if (zeros + qs > moves1) {
                f01 = true;
            }
            --ones;
            ++zeros;
            if (ones + qs > moves0) {
                f10 = true;
            }
        }
    }

    if (f00) {
        fout << "00\n";
    }
    if (f01) {
        fout << "01\n";
    }
    if (f10) {
        fout << "10\n";
    }
    if (f11) {
        fout << "11\n";
    }


    return 0;
}