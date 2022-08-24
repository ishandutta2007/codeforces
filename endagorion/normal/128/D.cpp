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
    int n;
    fin >> n;
    vector< int > a(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }
    sort(a.begin(), a.end());
    bool ok = true;
    int cur = -1;
    int q = 0;
    for (int i = 0; i < n; ++i) {
        if (q == 0) {
            if (cur != -1 && a[i] != a[i - 1]) {
                ok = false;
                break;
            }
            q = 1;
            cur = a[i];
        } else {
            if (cur == a[i]) {
                ++q;
            } else {
                if (cur == a[i] - 1) {
                    --q;
                } else {
                    ok = false;
                    break;
                }
            }
        }
    }

    ok &= q == 0;
    if (ok) {
        fout << "YES\n";
    } else {
        fout << "NO\n";
    }
    
    return 0;
}