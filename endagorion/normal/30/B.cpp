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

int month[12] = {31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};

bool correct(vector< int > &date) {
    if (date[1] > 12) {
        return false;
    }
    int add = (date[1] == 2) && (date[2] % 4 == 0) ? 1 : 0;
    return date[0] <= month[date[1] - 1] + add;
}

int years(vector< int > &first, vector< int > &second) {
    int diff = second[2] - first[2];
    if (first[1] > second[1] || (first[1] == second[1] && first[0] > second[0])) {
        --diff;
    }
    return diff;
}

int main() {
    string s;
    fin >> s;
    vector< int > final(3);
    for (int i = 0; i < 3; ++i) {
        final[i] = 10 * (s[3 * i] - '0') + (s[3 * i + 1] - '0');
    }

    fin >> s;
    vector< int > birth(3);
    for (int i = 0; i < 3; ++i) {
        birth[i] = 10 * (s[3 * i] - '0') + (s[3 * i + 1] - '0');
    }

    sort(birth.begin(), birth.end());
    while (true) {
        if (correct(birth) && years(birth, final) >= 18) {
            fout << "YES\n";
            return 0;
        }
        if (!next_permutation(birth.begin(), birth.end())) {
            break;
        }
    }

    fout << "NO\n";
    return 0;
}