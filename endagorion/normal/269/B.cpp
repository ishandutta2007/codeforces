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

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, M;
    cin >> N >> M;
    vector< int > a(N);
    for (int i = 0; i < N; ++i) {
        double trash;
        cin >> a[i] >> trash;
        --a[i];
    }

    vector< vector<int> > minW(N + 1, vector<int>(M, 1e9));
    minW[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j + 1 < M) {
                minW[i][j + 1] = min(minW[i][j + 1], minW[i][j]);
            }
            if (a[i] == j) {
                minW[i + 1][j] = min(minW[i + 1][j], minW[i][j]);
            }
            if (a[i] == j + 1) {
                minW[i + 1][j + 1] = min(minW[i + 1][j + 1], minW[i][j]);
            }
            minW[i + 1][j] = min(minW[i + 1][j], minW[i][j] + 1);
        }
    }
    for (int j = 0; j + 1 < M; ++j) {
        minW[N][j + 1] = min(minW[N][j + 1], minW[N][j]);
    }
    cout << minW[N][M - 1] << '\n';

	return 0;
}