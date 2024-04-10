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

    int N, M, H, T;
    fin >> N >> M >> H >> T;
    vector< vector<int> > edges(N);
    vector< set<int> > sedges(N);
    for (int i = 0; i < M; ++i) {
        int x, y;
        fin >> x >> y;
        --x; --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
        sedges[x].insert(y);
        sedges[y].insert(x);
    }

    for (int i = 0; i < N; ++i) {
        sort(edges[i].begin(), edges[i].end());
    }

    for (int x = 0; x < N; ++x) {
        int A = edges[x].size();
        if (A < H + 1) {
            continue;
        }
        for (size_t j = 0; j < edges[x].size(); ++j) {
            int y = edges[x][j];
            int B = edges[y].size();
            bool ok = false;
            if (B < T + 1) {
                continue;
            }
            if (B >= H + T + 1) {
                fout << "YES\n";
                fout << x + 1 << ' ' << y + 1 << '\n';
                vector<int> used;
                for (int i = H, k = 0; i > 0; ++k) {
                    if (edges[x][k] != y) {
                        --i;
                        used.push_back(edges[x][k]);
                        fout << edges[x][k] + 1 << ' ';
                    }
                }
                fout << '\n';
                for (int i = T, k = 0; i > 0; ++k) {
                    if (edges[y][k] != x && find(used.begin(), used.end(), edges[y][k]) == used.end()) {
                        --i;
                        fout << edges[y][k] + 1 << ' ';
                    }
                }
                fout << '\n';
                return 0;
            } else {
                vector<int> common;
                int i1 = 0, i2 = 0;
                while (i1 < A && i2 < B) {
                    if (edges[x][i1] == edges[y][i2]) {
                        common.push_back(edges[x][i1]);
                        ++i1; ++i2;
                        continue;
                    }
                    if (edges[x][i1] < edges[y][i2]) {
                        ++i1;
                    } else {
                        ++i2;
                    }
                }
                int C = common.size();
                int L = max(H - A + C + 1, 0) + max(T - B + C + 1, 0);
                if (L > C) {
                    continue;
                }
                fout << "YES\n";
                fout << x + 1 << ' ' << y + 1 << '\n';
                int P = max(0, H - A + C + 1), Q = L - P;
                for (int i = H - P, k = 0; i > 0; ++k) {
                    int z = edges[x][k];
                    if (z != y && find(common.begin(), common.end(), z) == common.end()) {
                        --i;
                        fout << z + 1 << ' ';
                    }
                }
                for (int i = 0; i < P; ++i) {
                    fout << common[i] + 1 << ' ';
                }
                fout << '\n';
                for (int i = T - Q, k = 0; i > 0; ++k) {
                    int z = edges[y][k];
                    if (z != x && find(common.begin(), common.end(), z) == common.end()) {
                        --i;
                        fout << z + 1 << ' ';
                    }
                }
                for (int i = P; i < P + Q; ++i) {
                    fout << common[i] + 1 << ' ';
                }   
                fout << '\n';
                return 0;
            }
        }
    }

    fout << "NO\n";

	return 0;
}