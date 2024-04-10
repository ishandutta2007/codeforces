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

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);


int main() {
	fout.precision(10);
	fout << fixed;

    int M, K;
    fin >> M >> K;
    vector<bool> fav(M);
    for (int i = 0; i < K; ++i) {
        int x;
        fin >> x;
        fav[x - 1] = true;
    }

    int N;
    fin >> N;
    vector<int> minf(N), maxf(N);
    for (int i = 0; i < N; ++i) {
        string s;
        int q;
        fin >> s >> q;
        int favc = 0, unk = 0, nfavc = 0;
        for (int j = 0; j < q; ++j) {
            int x;
            fin >> x;
            --x;
            if (x < 0) {
                ++unk;
            } else {
                if (fav[x]) {
                    ++favc;
                } else {
                    ++nfavc;
                }
            }
        }
        minf[i] = favc + max(0, unk - M + K + nfavc);
        maxf[i] = min(favc + unk, K);
    }

    for (int i = 0; i < N; ++i) {
        bool yes = true, no = false;
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                continue;
            }
            if (maxf[j] > minf[i]) {
                yes = false;
            }
            if (maxf[i] < minf[j]) {
                no = true;
            }
        }
        if (yes) {
            fout << "0\n";
        } else {
            if (no) {
                fout << "1\n";
            } else {
                fout << "2\n";
            }
        }
    }

	return 0;
}