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

long long side(long long d) {
    if (d <= 0) {
        return 0;
    }
    return d * d;
}

long long corn(long long d) {
    if (d <= 0) {
        return 0;
    }
    return d * (d + 1) / 2;
}

int main() {
	fout.precision(10);
	fout << fixed;

    long long N, X, Y, C;
    fin >> N >> X >> Y >> C;
    --X; --Y;
    long long l = -1, r = 2 * N;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        long long q = 2 * m * (m + 1) + 1;
        q -= side(m - X) + side(m - (N - X - 1)) + side(m - Y) + side(m - (N - Y - 1));
        q += corn(m - (X + Y + 1)) + corn(m - (X + (N - Y - 1) + 1)) + corn(m - ((N - X - 1) + Y + 1)) + corn(m - ((N - X - 1) + (N - Y - 1) + 1));
        if (q >= C) {
            r = m;
        } else {
            l = m;
        }
        //cout << m << ' ' << q << '\n';
    }

    fout << r << '\n';

	return 0;
}