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
    int tBegin = -1, tEnd = -1;
    int maxLen = 0;
    for (int i = 0; i < N; ++i) {
        int t, c;
        cin >> t >> c;
        if (t >= tEnd) {
            tBegin = t;
            tEnd = t;
        }
        tEnd += c;
        if (tEnd - t > maxLen) {
            maxLen = tEnd - t;
        }
    }
    cout << tEnd << ' ' << maxLen << '\n';

	return 0;
}