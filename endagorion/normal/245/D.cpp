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
    vector<int> a(N);
    vector< vector<int> > b(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fin >> b[i][j];
            if (i != j) {
                a[i] |= b[i][j];
                a[j] |= b[i][j];
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        fout << a[i] << ' ';
    }
    fout << '\n';
    
	return 0;
}