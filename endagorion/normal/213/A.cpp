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
    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        fin >> p[i];
        --p[i];
    }
    vector< vector<int> > a(N);
    for (int i = 0; i < N; ++i) {
        int k;
        fin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            fin >> x;
            --x;
            a[x].push_back(i);
        }
    }
    
    int ans = 1e9;
    for (int b = 0; b < 3; ++b) {
        int c = b;
        int res = 0;
        vector<int> toUnlock(N);
        for (int i = 0; i < N; ++i) {
            for (size_t j = 0; j < a[i].size(); ++j) {
                ++toUnlock[a[i][j]];
            }
        }
        int left = N;
        while (left > 0) {
            int changed = 1;
            while (changed) {
                changed = 0;
                for (int i = 0; i < N; ++i) {
                    if (toUnlock[i] == 0 && p[i] == c) {
                        toUnlock[i] = -1;
                        ++res;
                        changed = 1;
                        --left;
                        for (size_t j = 0; j < a[i].size(); ++j) {
                            --toUnlock[a[i][j]];
                        }
                    }
                }
            }
            if (left > 0) {
                ++res;
                c = (c + 1) % 3;
            }
        }
        ans = min(ans, res);
    }
    
    fout << ans << '\n';

	return 0;
}