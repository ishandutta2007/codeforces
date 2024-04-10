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
    vector< long long > count(256, 0);
    fin >> s;
    for (size_t i = 0; i < s.length(); ++i) {
        ++count[s[i]];
    }
    long long ans = 0;
    for (int i = 0; i < 256; ++i) {
        ans += count[i] * count[i];
    }

    fout << ans << '\n';
    return 0;
}