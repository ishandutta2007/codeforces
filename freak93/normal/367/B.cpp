#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, M, P;
    cin >> N >> M >> P;

    vector< vector<int> > V(P);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        V[i % P].push_back(x);
    }

    map<int, int> Map;
    int difference = 0;
    for (int i = 0; i < M; ++i) {
        int x; cin >> x;
        ++Map[x];
        ++difference;
    }

    vector<int> answer;
    for (int i = 0; i < P; ++i) {
        if (int(V[i].size()) < M)
            continue;
        map<int, int> now = Map;
        int nowdiff = difference;

        for (int j = 0; j < int(V[i].size()); ++j) {
            nowdiff -= abs(now[V[i][j]]);
            now[V[i][j]]--;
            nowdiff += abs(now[V[i][j]]);

            if (j >= M) {
                nowdiff -= abs(now[V[i][j - M]]);
                now[V[i][j - M]]++;
                nowdiff += abs(now[V[i][j - M]]);
            }

            if (j >= M - 1 && nowdiff == 0)
                answer.push_back(i + (j - M + 1) * P);
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (auto &x : answer)
        cout << x + 1 << " ";
    cout << "\n";
}