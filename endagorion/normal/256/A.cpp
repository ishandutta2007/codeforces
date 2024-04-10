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
    map< int, int > inpos;
    for (int i = 0; i < N; ++i) {
        int y;
        fin >> y;
        if (inpos.count(y) == 0) {
            int t = inpos.size();
            inpos[y] = t;            
        }
        int x = inpos[y];
        a[i] = x;
    }

    int K = inpos.size();
    vector< vector<int> > prevP(K, vector<int>(N, -1));
    for (int i = 0; i < K; ++i) {
        int c = -1;
        for (int j = 0; j < N; ++j) {
            prevP[i][j] = c;
            if (a[j] == i) {
                c = j;
            }
        }
    }

    vector< vector<int> > maxW(N, vector<int>(N));
    int ans = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (prevP[a[i]][j] != -1) {
                maxW[i][j] = maxW[j][prevP[a[i]][j]] + 1;
            } else {
                maxW[i][j] = 2;
            }
            ans = max(ans, maxW[i][j]);
        }
    }

    fout << ans << '\n';

	return 0;
}