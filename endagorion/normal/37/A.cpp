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

int main() {
	fout.precision(10);
	fout << fixed;

    int N;
    fin >> N;
    vector<int> a(N + 1);
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
    }
    a[N] = 1e9;
    sort(a.begin(), a.end());
    int maxh = 0, q = 0;
    int c = 1;
    for (int i = 1; i < N + 1; ++i) {
        if (a[i] == a[i - 1]) {
            ++c;
        } else {
            ++q;
            maxh = max(maxh, c);
            c = 1;
        }
    }

    fout << maxh << ' ' << q << '\n';

	return 0;
}