#pragma comment(linker, "/STACK:50000000")

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

int a[1000001], b[1000001];
int bb[1000001], c[3000001];

int main() {
	fout.precision(10);
	fout << fixed;

	for (int i = 1; i <= 1000000; ++i) {
		bb[i] = -1;
	}

	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < M; ++i) {
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < M; ++i) {
		bb[b[i]] = i;
	}
	for (int i = 0; i < 2 * N; ++i) {
		c[i] = bb[a[i % N]];
	}

	int l = 0, r = 0;
	while (l < N && c[l] < 0) {
		++l; ++r;
	}
	
	int wrap = 0;
	int ans = 0;

	while (l < N) {
		while (l < N && c[l] < 0) {
			++l; ++r;
		}	
		int begin = c[l];
		++r;
		while (1) {
			if (c[r] < 0) {
				break;
			}
			if (c[r] <= c[r - 1]) {
				++wrap;
			}
			int qb = c[r] + wrap * M;
			if (qb - begin >= M) {
				if (c[r] <= c[r - 1]) {
					--wrap;
				}
				break;
			}
			++r;
		}
		--r;
		ans = max(ans, r - l + 1);
		++l;
		if (l > 0 && c[l] <= c[l - 1] && c[l] >= 0) {
			--wrap;
		}
	}

	printf("%d\n", ans);

	return 0;
}