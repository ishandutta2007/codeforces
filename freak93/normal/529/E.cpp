#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;
    map<int, vector< pair<int, int> > > M;
    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        V[i] = x;
        for (int j = 0; j <= K; ++j)
            M[j * x].push_back(make_pair(j, i));
    }
    M[0].push_back(make_pair(0, -1));
    for (auto &p : M)
        sort(p.second.begin(), p.second.end());

    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int x; cin >> x;
        int answer = numeric_limits<int>::max();
        for (int j = 0; j < N; ++j)
            for (int k = 0; k <= K && k * V[j] <= x; ++k) {
                int y = x - k * V[j];
                if (!M.count(y))
                    continue;
                if (M[y].front().second == j) {
                    if (M[y].size() > 1)
                        answer = min(answer, M[y][1].first + k);
                } else
                    answer = min(answer, M[y][0].first + k);
            }
        if (answer > K)
            answer = -1;
        cout << answer << "\n";
    }
}