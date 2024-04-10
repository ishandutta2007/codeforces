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

const long long P = 257;
const long long Q = 2093123897;

int n;

vector< long long > hash, invhash;
vector< long long > degs;
vector< vector< int > > stable, maxpos;
vector< int > nonGr;

void fillHash(const string &s) {
    hash.resize(s.length());
    hash[0] = s[0];
    for (int i = 1; i < n; ++i) {
        hash[i] = (hash[i - 1] * P + s[i]) % Q;
    }

    invhash.resize(s.length());
    invhash[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        invhash[i] = (invhash[i + 1] * P + s[i]) % Q;
    }

    degs.resize(s.length());
    degs[0] = 1;
    for (int i = 1; i < n; ++i) {
        degs[i] = (degs[i - 1] * P) % Q;
    }
}

long long getHash(int l, int r) {
    long long ans = hash[r];
    if (l == 0) {
        return ans;
    }
    long long cut = hash[l - 1];
    cut = (cut * degs[r - l + 1]) % Q;
    ans = (ans - cut + Q) % Q;
    return ans;
}

long long getInvHash(int l, int r) {
    long long ans = invhash[l];
    if (r == n - 1) {
        return ans;
    }

    long long cut = invhash[r + 1];
    cut = (cut * degs[r - l + 1]) % Q;
    ans = (ans - cut + Q) % Q;
    return ans;
}

void fillSTable(const vector< int > &arr) {
    stable.assign(17, vector< int >(n));
    maxpos.assign(17, vector< int >(n));
    stable[0] = arr;
    for (int i = 0; i < n; ++i) {
        maxpos[0][i] = i;
    }
    for (int i = 1; i < 17; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j + (1 << (i - 1)) >= n) {
                stable[i][j] = -1;
                maxpos[i][j] = -1;
            } else {
                int left = stable[i - 1][j];
                int right = stable[i - 1][j + (1 << (i - 1))];
                stable[i][j] = max(stable[i - 1][j], stable[i - 1][j + (1 << (i - 1))]);
                if (left > right) {
                    maxpos[i][j] = maxpos[i - 1][j];
                } else {
                    maxpos[i][j] = maxpos[i - 1][j + (1 << (i - 1))];
                }
            }
        }
    }

    nonGr.resize(n + 1);
    nonGr[1] = 0;
    for (int i = 2; i <= n; ++i) {
        nonGr[i] = nonGr[i / 2] + 1;
    }
}

int getMax(int l, int r) {
    if (l > r) {
        return -1;
    }
    int lev = nonGr[r - l + 1];
    int left = stable[lev][l];
    int right = stable[lev][r - (1 << lev) + 1];
    if (left > right) {
        return maxpos[lev][l];
    } else {
        return maxpos[lev][r - (1 << lev) + 1];
    }
}

int main() {
    string s;
    fin >> s;
    n = s.length();
    fillHash(s);
    vector< int > maxpalind(n);
    for (int i = 0; i < n; ++i) {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (i - m >= 0 && i + m < n && getHash(i - m, i + m) == getInvHash(i - m, i + m)) {
                l = m;
            } else {
                r = m;
            }
        }
        maxpalind[i] = l;
    }
    
    fillSTable(maxpalind);

    int maxl = 0;
    int prefb, prefl, midb, midl;

    for (int i = 0; i < n; ++i) {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (i + m < n - m && getHash(i, i + m - 1) == getInvHash(n - m, n - 1)) {
                l = m;
            } else {
                r = m;
            }
        }
        int prefLen = l;
        int bl = i + l;
        int br = n - l - 1;
        l = 0;
        r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (bl + m <= br - m && maxpalind[getMax(bl + m, br - m)] >= m) {
                l = m;
            } else {
                r = m;
            }
        }
        int midLen = l;
        if (2 * prefLen + 2 * midLen + 1 > maxl) {
            maxl = 2 * prefLen + 2 * midLen + 1;
            prefb = i;
            prefl = prefLen;
            midb = getMax(bl + l, br - l) - l;
            midl = midLen;
        }
    }

    if (prefl == 0) {
        fout << "1\n";
        fout << midb + 1 << ' ' << 2 * midl + 1 << '\n';
    } else {
        fout << "3\n";
        fout << prefb + 1 << ' ' << prefl << '\n';
        fout << midb + 1 << ' ' << 2 * midl + 1 << '\n';
        fout << n - prefl + 1 << ' ' << prefl << '\n';
    }
    return 0;
}