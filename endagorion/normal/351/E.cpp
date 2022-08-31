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

int p[3000];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
        p[i] = abs(p[i]);
    }
    for (int i = 0; i < N; ++i) {
        int ch = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                continue;
            }
            if (abs(p[j]) < abs(p[i])) {
                if (j < i) {
                    ++ch;
                } else {
                    --ch;
                }
            }
        }
        if (ch < 0) {
            p[i] = -p[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (p[i] > p[j]) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';

	return 0;
}