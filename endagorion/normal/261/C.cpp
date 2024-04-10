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

    long long N, T;
    fin >> N >> T;
    ++N;
    
    vector< vector<long long> > CNK(41, vector<long long>(41, 0));
    CNK[0][0] = 1;
    for (int i = 0; i <= 40; ++i) {
        CNK[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            CNK[i][j] = CNK[i - 1][j - 1] + CNK[i - 1][j];
        }
    }
    int h = 0;
    while ((1LL << h) < T) {
        ++h;
    }
    if ((1LL << h) != T) {
        fout << 0 << '\n';
        return 0;
    }
    ++h;

    long long ans = 0;
    for (int i = 40; i >= 0 && h >= 0; --i) {
        if ((1LL << i) <= N) {
            ans += CNK[i][h];
            N -= (1LL << i);
            --h;
        }
    }
    if (h == 0) {
        ++ans;
    }
    if (T == 1) {
        --ans;
    }
    
    fout << ans << '\n';

	return 0;
}