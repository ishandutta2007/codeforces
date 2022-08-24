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

int p[5000];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }
    int inv = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (p[i] > p[j]) {
                ++inv;
            }
        }
    }
    int ans;
    if (inv % 2 == 0) {
        ans = inv * 2;
    } else {
        ans = inv * 2 - 1;
    }
    cout << ans << '\n';

	return 0;
}