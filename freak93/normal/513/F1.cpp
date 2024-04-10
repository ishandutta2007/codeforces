#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <ctime>

using namespace std;

const int kMaxN = 22;
int dist[kMaxN][kMaxN][kMaxN][kMaxN];

const int kMaxNodes = 22 * 22 * 4 + 100;

vector<int> E[kMaxNodes];
int used[kMaxNodes];

struct Event {
    int64_t when;
    int from;
    int to;

    bool operator<(const Event& that) const {
        return when < that.when;
    }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> changed;
bool dfs(int node, int to) {
    if (node == to)
        return true;
    if (used[node])
        return false;
    changed.push_back(node);
    used[node] = true;
    for (int i = 0; i < int(E[node].size()); ++i)
        if (dfs(E[node][i], to)) {
            int x = E[node][i];
            E[x].push_back(node);
            swap(E[node][i], E[node].back());
            E[node].pop_back();
            return true;
        }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int N, M, males, females; cin >> N >> M >> males >> females;

    vector<string> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];

    queue< pair<int, int> > Q;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (S[i][j] == '.') {
                for (int k = 0; k < N; ++k)
                    for (int p = 0; p < M; ++p)
                        dist[i][j][k][p] = -1;

                Q.push(make_pair(i, j));
                dist[i][j][i][j] = 0;
                while (!Q.empty()) {
                    int x, y;
                    x = Q.front().first;
                    y = Q.front().second;
                    Q.pop();

                    for (int l = 0; l < 4; ++l) {
                        int newx = x + dx[l];
                        int newy = y + dy[l];
                        if (newx < 0 || newx >= N)
                            continue;
                        if (newy < 0 || newy >= M)
                            continue;
                        if (S[newx][newy] == '#')
                            continue;
                        if (dist[i][j][newx][newy] == -1) {
                            dist[i][j][newx][newy] = dist[i][j][x][y] + 1;
                            Q.push(make_pair(newx, newy));
                        }
                    }
                }
            }

    vector<int> XM(males), YM(males), TM(males);
    vector<int> XF(females), YF(females), TF(females);
    int X, Y, T; cin >> X >> Y >> T;
    --X;
    --Y;
    for (int i = 0; i < males; ++i) {
        cin >> XM[i] >> YM[i] >> TM[i];
        --XM[i];
        --YM[i];
    }
    for (int i = 0; i < females; ++i) {
        cin >> XF[i] >> YF[i] >> TF[i];
        --XF[i];
        --YF[i];
    }

    if (males < females) {
        XM.push_back(X);
        YM.push_back(Y);
        TM.push_back(T);
        ++males;
    } else {
        XF.push_back(X);
        YF.push_back(Y);
        TF.push_back(T);
        ++females;
    }

    if (males != females) {
        cout << "-1\n";
        return 0;
    }

    int source = males + 2 * N * M + females;
    int sink = source + 1;

    for (int i = 0; i <= sink; ++i)
        E[i].reserve(kMaxNodes);

   for (int i = 0; i <= sink; ++i)
        E[i].clear();
    for (int i = males; i < males + N * M; ++i)
        E[i].push_back(i + N * M);

    vector<Event> ev;
    for (int i = 0; i < males; ++i) {
        E[source].push_back(i);
        int x = XM[i];
        int y = YM[i];
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < M; ++k) {
                if (dist[x][y][j][k] == -1)
                    continue;
                ev.push_back(Event{1LL * dist[x][y][j][k] * TM[i], i, males + j * M + k});
            }
    }
    for (int i = 0; i < females; ++i) {
        E[males + 2 * N * M + i].push_back(sink);
        int x = XF[i];
        int y = YF[i];
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < M; ++k) {
                if (dist[x][y][j][k] == -1)
                    continue;
                ev.push_back(Event{1LL * dist[x][y][j][k] * TF[i], males + N * M + j * M + k, males + 2 * N * M + i});
            }
    }

    sort(ev.begin(), ev.end());
    int answer = 0;
    set<int> fromBoys;
    set<int> toGirls;
    for (int i = 0; i < int(ev.size()); ) {
        int j;
        for (j = i; j < int(ev.size()) && ev[j].when == ev[i].when; ++j) {
            E[ev[j].from].push_back(ev[j].to);
            if (ev[j].to >= males && ev[j].to < males + N * M)
                fromBoys.insert(ev[j].to);
            if (ev[j].from >= males + N * M && ev[j].from < males + 2 * N * M)
                toGirls.insert(ev[j].from);
        }

        if (int(fromBoys.size()) < males || int(toGirls.size()) < females) {
            i = j;
            continue;
        }

        memset(used, 0, sizeof(used));
        while (dfs(source, sink)) {
            ++answer;
            for (auto &x : changed)
                used[x] = false;
            changed.clear();
        }

        if (answer == males) {
            cout << ev[i].when << "\n";
            return 0;
        }

        i = j;
    }
    cout << "-1\n";
}