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

	int N, M;
	fin >> N >> M;
	vector<string> field(N);
	for (int i = 0; i < N; ++i) {
		fin >> field[i];
	}

	int ans = 0;
	int minA = N, minB = M;
	for (int A = 1; A <= N; ++A) {
		if (N % A != 0) {
			continue;
		}
		for (int B = 1; B <= M; ++B) {
			if (M % B != 0) {
				continue;
			}
			set<string> pieces;
			for (int x = 0; x < N; x += A) {
				for (int y = 0; y < M; y += B) {
					string piece;
					for (int xx = 0; xx < A; ++xx) {
						for (int yy = 0; yy < B; ++yy) {
							piece += field[x + xx][y + yy];
						}
					}
					string normPiece = piece;
					piece = "";
					for (int xx = A - 1; xx >= 0; --xx) {
						for (int yy = B - 1; yy >= 0; --yy) {
							piece += field[x + xx][y + yy];
						}
					}
					normPiece = min(normPiece, piece);
					piece = "";
					if (A == B) {
						for (int yy = 0; yy < B; ++yy) {
							for (int xx = A - 1; xx >= 0; --xx) {
								piece += field[x + xx][y + yy];
							}
						}
						normPiece = min(normPiece, piece);
						piece = "";
						for (int yy = B - 1; yy >= 0; --yy) {
							for (int xx = 0; xx < A; ++xx) {
								piece += field[x + xx][y + yy];
							}
						}
						normPiece = min(normPiece, piece);
						piece = "";
					}
					pieces.insert(normPiece);
				}
			}
			if (pieces.size() == N * M / A / B) {
				++ans;
				if (A * B < minA * minB || (A * B == minA * minB && A < minA)) {
					minA = A;
					minB = B;
				}
			}
		}
	}

	fout << ans << '\n';
	fout << minA << ' ' << minB << '\n';

	return 0;
}