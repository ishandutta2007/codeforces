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
    scanf("%d%d", &N, &M);
    vector<int> degs(N);
    for (int i = 0; i < M; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        ++degs[x]; ++degs[y];
    }

    bool bus = true;
    for (int i = 0; i < N; ++i) {
        bus = bus & (degs[i] <= 2);
        if (degs[i] == N - 1 && M == N - 1) {
            cout << "star topology\n";
            return 0;
        }
    }
    if (bus) {
        if (M == N - 1) {
            cout << "bus topology\n";
            return 0;
        }
        if (M == N) {
            cout << "ring topology\n";
            return 0;
        }
    }
    
    cout << "unknown topology\n";

	return 0;
}