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

const int MAXN = 150000;
const int INF = 1e9;

bool isBad[MAXN];
vector< vector<int> > edges;
int minD[MAXN], minU[MAXN];

int M, N, D;

void dfs(int x, int p) {
    if (isBad[x]) {
        minD[x] = 0;
    } else {
        minD[x] = -INF;
    }
    for (size_t i = 0; i < edges[x].size(); ++i) {
        int u = edges[x][i];
        if (u == p) {
            continue;
        }
        dfs(u, x);
        minD[x] = max(minD[x], minD[u] + 1);
    }
}

void dfs2(int x, int p) {
    if (isBad[x]) {
        minU[x] = max(minU[x], 0);
    }

    int min1 = -INF, min2 = -INF;
    for (size_t i = 0; i < edges[x].size(); ++i) {
        int u = edges[x][i];
        if (u == p) {
            continue;
        }
        if (minD[u] >= min1) {
            min2 = min1;
            min1 = minD[u];
        } else {
            if (minD[u] >= min2) {
                min2 = minD[u];
            }
        }
    }
    for (size_t i = 0; i < edges[x].size(); ++i) {
        int u = edges[x][i];
        if (u == p) {
            continue;
        }
        if (minD[u] == min1) {
            minU[u] = 1 + max(1 + min2, minU[x]);
        } else {
            minU[u] = 1 + max(1 + min1, minU[x]);
        }
        dfs2(u, x);
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d%d%d", &N, &M, &D);
    for (int i = 0; i < M; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        isBad[x] = true;
    }

    edges.resize(N);
    for (int i = 0; i < N - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for (int i = 0; i < N; ++i) {
        minD[i] = minU[i] = -INF;
    }

    dfs(0, -1);
    dfs2(0, -1);
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (max(minD[i], minU[i]) <= D) {
            ++count;
            //cout << i + 1 << '\n';
        }
    }

    cout << count << '\n';

	return 0;
}