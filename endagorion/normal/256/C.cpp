#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

long long low(long long x) {
    long long l = 0, r = min(10000LL, x - 1);
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (m * m * m * m >= x) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

long long high(long long x) {
    long long l = 0, r = min(100000000LL, x - 1);
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (m * m > x) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

int main() {
	fout.precision(10);
	fout << fixed;

    int N;
    fin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
    }
    vector<int> gr(1000000);
    gr[0] = gr[1] = 0;
    long long l = 1, r = 2;
    vector<int> pres(10000);
    pres[0] = 1;
    int t = 0;
    int c = 0;
    vector<long long> b, v;
    b.push_back(0);
    v.push_back(0);
    for (int i = 2; i < 1000000; ++i) {
        while (l * l * l * l < i) {
            --pres[gr[l]];
            ++l;
        }
        while (r * r <= i) {
            ++pres[gr[r]];
            ++r;
        }
        int q = 0;
        while (pres[q] > 0) {
            ++q;
        }
        gr[i] = q;
        t = max(t, gr[i]);
        if (gr[i] != gr[i - 1]) {
            b.push_back(i);
            v.push_back(gr[i]);
        }
        //fout << gr[i] << '\n';
    }
    b.push_back(1000000);
    v.push_back(-1);


    //fout << c << '\n';

    int res = 0;
    for (int i = 0; i < N; ++i) {
        long long l = low(a[i]), h = high(a[i]);
        vector<bool> pres(5);
        for (size_t j = 0; j + 1 < v.size(); ++j) {
            if (min(h, b[j + 1]) > max(l, b[j])) {
                pres[v[j]] = true;
            }
        }
        int q = 0;
        while (pres[q]) {
            ++q;
        }
        res ^= q;
    }

    fout << (res > 0 ? "Furlo" : "Rublo") << '\n';

	return 0;
}