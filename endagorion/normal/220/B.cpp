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

int pr[500][100001];

int main() {
	fout.precision(10);
	fout << fixed;

    int N, M;
    fin >> N >> M;
    vector<int> a(N), c(N + 1);

    for (int i = 0; i < N; ++i) {
        fin >> a[i];
        if (a[i] <= N) {
            ++c[a[i]];
        }
    }

    vector<int> poss;
    for (int i = 1; i <= N; ++i) {
        if (c[i] >= i) {
            poss.push_back(i);
        }
    }
    int K = poss.size();
    for (int i = 0; i < K; ++i) {
        pr[i][0] = 0;
        for (int j = 0; j < N; ++j) {
            pr[i][j + 1] = pr[i][j];
            if (a[j] == poss[i]) {
                ++pr[i][j + 1];
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        int l, r;
        fin >> l >> r;
        --l;
        int ans = 0;
        for (int j = 0; j < K; ++j) {
            if (pr[j][r] - pr[j][l] == poss[j]) {
                ++ans;
            }
        }
        fout << ans << '\n';
    }

	return 0;
}