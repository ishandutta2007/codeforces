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
    s = '0' + s;
    int N = s.length();
    vector< int > mine(N, 1e9);
    vector< int > prev0(N), prev1(N);
    int cur0 = -1, cur1 = -1;
    for (int i = 0; i < N; ++i) {
        prev0[i] = cur0;
        prev1[i] = cur1;
        if (s[i] == '0') {
            cur0 = i;
        } else {
            cur1 = i;
        }
    }
    vector< int > len(N), ans(N);
    len[0] = 1;
    ans[0] = 1;
    for (int i = 1; i < N; ++i) {
        int plus, minus;
        if (prev1[i] == -1) {
            plus = 1;
        } else {
            plus = 1 + len[prev1[i]];
        }
        minus = 1 + len[prev0[i]];
        if (plus < minus) {
            len[i] = plus;
            ans[i] = 1;
        } else {
            len[i] = minus;
            ans[i] = -1;
        }
    }

    int i = N - 1;
    while (s[i] == '0') {
        --i;
    }
    fout << len[i] << '\n';
    while (i >= 0) {
        if (ans[i] == 1) {
            fout << "+2^" << N - i - 1 << '\n';
            i = prev1[i];
        } else {
            fout << "-2^" << N - i - 1 << '\n';
            i = prev0[i];
        }
    }

    return 0;
}