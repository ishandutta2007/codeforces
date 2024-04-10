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

int f[501][501];
int p[501];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &f[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &p[i]);
        --p[i];    
    }

    vector<long long> ans(N);
    for (int i = N - 1; i >= 0; --i) {
        int x = p[i];
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                f[j][k] = min(f[j][k], f[j][x] + f[x][k]);
            }
        }
        for (int j = i; j < N; ++j) {
            for (int k = i; k < N; ++k) {
                ans[i] += f[p[j]][p[k]];
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

	return 0;
}