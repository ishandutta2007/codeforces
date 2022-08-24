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

const int MAXN = 100000 + 10;

int N, M;
long long h[MAXN], p[MAXN];

long long time(long long head, long long left, long long right) {
    return right - left + min(std::abs(head - left), std::abs(right - head));
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> p[i];
    }
    long long l = -1, r = 2e10 + 1;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        int k = 0;
        for (int i = 0; i < N; ++i) {
            int l = k;
            while (l < M && time(h[i], p[k], p[l]) <= m) {
                ++l;
            }
            k = l;
        }
        if (k == M) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';

	return 0;
}