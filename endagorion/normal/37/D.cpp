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

const long long P = 1000000000 + 7;

long long deg(long long x, long long d) {
    if (x == 0) {
        return 0;
    }
    if (d == 0) {
        return 1;
    }
    long long y = deg(x, d / 2);
    y = (y * y) % P;
    if (d % 2) {
        y = (y * x) % P;
    }
    return y;
}

long long inv(long long x) {
    return deg(x, P - 2);
}

int main() {
	fout.precision(10);
	fout << fixed;

    int M;
    fin >> M;
    vector<int> X(M), Y(M);
    int s = 0;
    for (int i = 0; i < M; ++i) {
        fin >> X[i];
        s += X[i];
    }
    for (int i = 0; i < M; ++i) {
        fin >> Y[i];
    }
    vector<long long> facts(1101), invf(1101);
    facts[1] = invf[1] = 1;
    for (int i = 2; i <= 1100; ++i) {
        facts[i] = (facts[i - 1] * i) % P;
        invf[i] = inv(facts[i]);
    }
    vector< vector<long long> > cnk(1101, vector<long long>(1101, 0));
    cnk[0][0] = 1;
    for (int i = 1; i <= 1100; ++i) {
        cnk[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % P;
        }
    }

    vector< vector<long long> > ways(M + 1, vector<long long>(1001));
    ways[M][0] = 1;
    for (int i = 1; i <= 1000; ++i) {
        ways[M][i] = 0;
    }
    for (int i = M - 1; i >= 0; --i) {
        for (int j = 0; j <= 1000; ++j) {
            for (int k = 0; k <= Y[i]; ++k) {
                if (j + X[i] - k <= 1000 && j + X[i] - k >= 0) { 
                    ways[i][j] += cnk[j + X[i]][k] * ways[i + 1][j + X[i] - k];
                    ways[i][j] %= P;
                }
            }
        }
    }

    long long ans = ways[0][0];
    for (int i = 0; i < M; ++i) {
        ans *= cnk[s][X[i]];
        ans %= P;
        s -= X[i];
    }

    fout << ans << '\n';

	return 0;
}