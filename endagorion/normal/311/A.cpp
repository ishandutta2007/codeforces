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
    int N, K;
    cin >> N >> K;
    if (K >= N * (N - 1) / 2) {
        cout << "no solution\n";
        return 0;
    }
    for (int i = 0; i < N - 1; ++i) {
        cout << i << ' ' << 10000 * i << '\n';
    }
    cout << N - 1 << ' ' << 0 << '\n';

	return 0;
}