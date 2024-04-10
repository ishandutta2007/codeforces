#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <cassert>
#include <limits>

#define int int64_t 

using namespace std;

static const int kLog = 28;
static const int kModulo = 998'244'353;

int pow(int x, int y) {
    if (y == 0)
        return 1;
    if (y % 2)
        return 1LL * x * pow(x, y - 1) % kModulo;
    int v = pow(x, y / 2);
    return 1LL * v * v % kModulo;
}

int32_t main() {
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    vector< vector<int> > edges[2];
    edges[0] = edges[1] = vector< vector<int> >(N);
    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        edges[0][x].emplace_back(y);
        edges[1][y].emplace_back(x);
    }

    vector< vector<int> > dist(kLog, vector<int>(N, -1));
    dist[0][0] = 0;
    queue< pair<int, int> > Q;
    Q.emplace(0, 0);
    while (!Q.empty()) {
        auto [node, transpose] = Q.front();
        Q.pop();

        for (auto &x : edges[transpose % 2][node])
            if (dist[transpose][x] == -1) {
                dist[transpose][x] = dist[transpose][node] + 1;
                Q.emplace(x, transpose);
            }
        if (transpose + 1 == kLog)
            continue;
        for (auto &x : edges[1 - transpose % 2][node])
            if (dist[transpose + 1][x] == -1) {
                dist[transpose + 1][x] = dist[transpose][node] + 1;
                Q.emplace(x, transpose + 1);
            }
    }

    for (int i = 0; i + 1 < kLog; ++i)
        for (int j = 0; j < N; ++j)
            if (dist[i][j] != -1 && (dist[i + 1][j] == -1 || dist[i][j] < dist[i + 1][j])) {
                dist[i + 1][j] = dist[i][j];
            }

    int answer = -1;
    for (int i = 0; i < kLog; ++i)
        if (dist[i][N - 1] != -1 && (answer == -1 || dist[i][N - 1] + (1LL << i) - 1 < answer))
            answer = dist[i][N - 1] + (1LL << i) - 1;

    if (answer != -1) {
        cout << answer % kModulo << "\n";
        return 0;
    }

    vector< vector< pair<int, int> > > distance(2, vector< pair<int, int> > (N, {numeric_limits<int>::max(), numeric_limits<int>::max()}));
    set< pair< pair<int, int>, pair<int, int> > > S;
    
    distance[0][0] = pair{0, 0};
    S.emplace(distance[0][0], pair{0, 0});
    while (!S.empty()) {
        auto [d, node] = *S.begin();
        S.erase(S.begin());

        for (auto &x : edges[node.first][node.second]) {
            if (distance[node.first][x] > pair{d.first, d.second + 1}) {
                S.erase(pair{distance[node.first][x], pair{node.first, x}});
                distance[node.first][x] = pair{d.first, d.second + 1};
                S.emplace(distance[node.first][x], pair{node.first, x});
            }
        }

        if (distance[node.first ^ 1][node.second] > pair{d.first + 1, d.second}) {
            S.erase(pair{distance[node.first ^ 1][node.second], pair{node.first ^ 1, node.second}});
            distance[node.first ^ 1][node.second] = pair{d.first + 1, d.second};
            S.emplace(pair{d.first + 1, d.second}, pair{node.first ^ 1, node.second});
        }
    }

    auto best = min(distance[0][N - 1], distance[1][N - 1]);
    answer = (pow(2, best.first) - 1 + best.second) % kModulo;

    cout << answer << "\n";
}