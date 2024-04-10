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
    if (d == 0) {
        return 1;
    }
    long long y = deg(x, d / 2);
    y = (y * y) % P;
    if (d % 2 == 1) {
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

    long long N, K;
    fin >> N >> K;

    vector<long long> C(N + 1);
    C[0] = 1;

    for (int i = 1; i <= N; ++i) {
        C[i] = ((C[i - 1] * (K + i - 1)) % P * inv(i)) % P;
    }

    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
    }
    vector<long long> ans(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            ans[i] += a[j] * C[i - j]; ans[i] %= P;
        }
        fout << ans[i] << ' ';
    }
    fout << '\n';

	return 0;
}