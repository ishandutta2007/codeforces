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

    long long minx = 1e9, maxx = -1e9, miny = 1e9, maxy = -1e9;
    long long S = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        long long x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        minx = min(minx, min(x1, x2));
        maxx = max(maxx, max(x1, x2));
        miny = min(miny, min(y1, y2));
        maxy = max(maxy, max(y1, y2));
        S += (x2 - x1) * (y2 - y1);
        minx = min(minx, min(x1, x2));
    }

    cout << (maxx - minx == maxy - miny && S == (maxx - minx) * (maxy - miny) ? "YES" : "NO") << '\n';

	return 0;
}