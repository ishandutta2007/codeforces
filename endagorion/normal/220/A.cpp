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
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int d = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] != b[i]) {
            ++d;
        }
    }

    fout << (d <= 2 ? "YES" : "NO") << '\n';

	return 0;
}