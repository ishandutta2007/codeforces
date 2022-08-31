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
    int N;
    cin >> N;
    vector<string> f(N);
    for (int i = 0; i < N; ++i) {
        cin >> f[i];
    }
    vector<int> row(N, -1), col(N, -1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (f[i][j] == '.') {
                row[i] = j;
                col[j] = i;
            }
        }
    }
    int frow = 0, fcol = 0;
    for (int i = 0; i < N; ++i) {
        if (row[i] != -1) {
            ++frow;
        }
        if (col[i] != -1) {
            ++fcol;
        }
    }

    if (frow == N) {
        for (int i = 0; i < N; ++i) {
            cout << i + 1 << ' ' << row[i] + 1 << '\n';
        }
        return 0;
    }

    if (fcol == N) {
        for (int i = 0; i < N; ++i) {
            cout << col[i] + 1 << ' ' << i + 1 << '\n';
        }
        return 0;
    }

    cout << -1 << '\n';

	return 0;
}