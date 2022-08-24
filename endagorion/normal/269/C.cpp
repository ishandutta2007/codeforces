#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
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

struct TEdge {
    int to, w;
    int id;
    bool rev;

    TEdge(int _to = 0, int _w = 0, int _id = 0, bool _rev = false)
        : to(_to)
        , w(_w)
        , id(_id)
        , rev(_rev)
    {
    }
};

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    cin >> N >> M;
    set< pair<int, int> > push;
    vector<int> ans(M, -1);
    vector<int> vis(M);
    vector<int> p(N);
    vector< vector<TEdge> > edges(N);
    for (int i = 0; i < M; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        edges[x].push_back(TEdge(y, w, i, false));
        edges[y].push_back(TEdge(x, w, i, true));
        p[x] += w;
        p[y] += w;
        if (x == 0) {
            p[y] -= 2 * w;
            vis[i] = true;
            ans[i] = 0;
        }
        if (y == 0) {
            p[x] -= 2 * w;
            vis[i] = true;
            ans[i] = 1;
        }
    }

    for (int i = 1; i + 1 < N; ++i) {
        push.insert(mp(p[i], i));
    }

    while (!push.empty()) {
        pair<int, int> cur = *push.begin();
        assert(cur.first == 0);
        push.erase(push.begin());
        int x = cur.second;
        for (size_t i = 0; i < edges[x].size(); ++i) {
            if (vis[edges[x][i].id]) {
                continue;
            }
            vis[edges[x][i].id] = true;
            int y = edges[x][i].to;
            int w = edges[x][i].w;
            if (y != N - 1) {
                push.erase(mp(p[y], y));
            }
            p[y] -= 2 * w;
            if (y != N - 1) {
                push.insert(mp(p[y], y));
            }
            if (edges[x][i].rev) {
                ans[edges[x][i].id] = 1;
            } else {
                ans[edges[x][i].id] = 0;
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        cout << ans[i] << '\n';
    }

	return 0;
}