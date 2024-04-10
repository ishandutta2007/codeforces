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
    vector<int> a(N), s(N + 1);
    s[0] = 0;
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
        s[i + 1] = s[i] + a[i];
    }

    vector< vector<int> > mw(N + 1, vector<int>(N + 1, 1e9));
    mw[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        int l = 0;
        int m = mw[i][0];
        for (int j = i + 1; j <= N; ++j) {
            while (l < i && s[i] - s[i - l - 1] <= s[j] - s[i]) {
                ++l;
                m = min(m, mw[i][l]);
            }
            mw[j][j - i] = min(mw[j][j - i], m + j - i - 1);
        }
    }
    
    int ans = 1e9;
    for (int i = 1; i <= N; ++i) {
        ans = min(ans, mw[N][i]);
    }

    fout << ans << '\n';

	return 0;
}