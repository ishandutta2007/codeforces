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

const int MAXN = 1000001;
vector<int> edges[MAXN];
int ind[MAXN];
int s, t;
int ans[MAXN];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        edges[y].pb(x);
        ++ind[x];
    }
    scanf("%d%d", &s, &t);
    --s; --t;
    for (int i = 0; i < N; ++i) {
        ans[i] = -1e9;
    }
    ans[t] = 0;
    set<int> layer[2];
    int cLayer = 0;
    layer[cLayer].insert(t);
    int d = 0;
    while (true) {
        set<int> &nextLayer = layer[1 - cLayer], &curLayer = layer[cLayer];
        while (!curLayer.empty()) {
            int x = *curLayer.begin();
            curLayer.erase(x);
            for (size_t i = 0; i < edges[x].size(); ++i) {
                int y = edges[x][i];
                if (ans[y] >= 0) {
                    continue;
                }
                --ind[y];
                if (ind[y] == 0) {
                    nextLayer.erase(y);
                    curLayer.insert(y);
                    ans[y] = ans[x];
                } else {
                    nextLayer.insert(y);
                }
            }
        }
        if (nextLayer.empty()) {
            break;
        }
        ++d;
        for (set<int>::iterator it = nextLayer.begin(); it != nextLayer.end(); ++it) {
            ans[*it] = d;
        }
        cLayer = 1 - cLayer;
    }
    if (ans[s] < 0) {
        printf("-1\n");
    } else {
        printf("%d\n", ans[s]);
    }

	return 0;
}