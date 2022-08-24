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

int ord[100001];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, M;
    scanf("%d%d", &N, &M);
    set< pair<int, int> > edges;
    for (int i = 0; i < M; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        if (x > y) {
            swap(x, y);
        }
        edges.insert(mp(x, y));
    }
    for (int i = 0; i < N; ++i) {
        ord[i] = i;
    }

    for (int q = 0; q < 10000000 / M; ++q) {
        random_shuffle(ord, ord + N);
        ord[N] = ord[0];
        bool ok = true;
        for (int i = 0; i < M; ++i) {
            int x = ord[i], y = ord[i + 1];
            if (x > y) {
                swap(x, y);
            }
            if (edges.count(mp(x, y)) > 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < M; ++i) {
                printf("%d %d\n", ord[i] + 1, ord[i + 1] + 1);
            }
            return 0;
        }
    }
    cout << -1 << '\n';

	return 0;
}