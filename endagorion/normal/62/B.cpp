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
    int n, k;
    fin >> n >> k;
    string s;
    fin >> s;
    vector< vector< int > > minDist(26, vector< int >(200001, 200001));
    for (int let = 0; let < 26; ++let) {
        int last = -1;
        for (int i = 0; i < 200001; ++i) {
            if (i < k && s[i] == 'a' + let) {
                last = i;
            }
            if (last != -1) {
                minDist[let][i] = min(minDist[let][i], i - last);
            }
        }
        last = -1;
        for (int i = 200000; i >= 0; --i) {
            if (i < k && s[i] == 'a' + let) {
                last = i;
            }
            if (last != -1) {
                minDist[let][i] = min(minDist[let][i], last - i);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        string t;
        fin >> t;
        long long ans = 0;
        for (size_t j = 0; j < t.length(); ++j) {
            if (minDist[t[j] - 'a'][j] == 200001) {
                ans += t.length();
            } else {
                ans += minDist[t[j] - 'a'][j];
            }
        }
        fout << ans << '\n';
    }
    return 0;
}