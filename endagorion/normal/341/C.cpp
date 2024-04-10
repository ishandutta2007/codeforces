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

const long long P = 1000000000 + 7;

int a[10000];
bool used[10000];
long long ways[2011][2011];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    int free = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        if (a[i] != -1) {
            --a[i];
        } else {
            ++free;
        }
    }

    int p = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] != -1 && a[a[i]] == -1) {
            ++p;
            --free;
        }
    }
    ways[0][0] = 1;
    for (int i = 0; i <= free; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (j > 0) {
                ways[i][j] += ways[i][j - 1] * j;
                if (i > 0) {
                    ways[i][j] += ways[i - 1][j] * i;
                }
            } else {
                if (i > 1) {
                    ways[i][j] += ways[i - 2][j + 1] * (i - 1);
                }
            }
            ways[i][j] %= P;
        }
    }
    cout << ways[free][p];

	return 0;
}