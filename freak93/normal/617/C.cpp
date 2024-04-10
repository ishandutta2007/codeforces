#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int64_t dist(int x1, int y1, pair<int, int> P) {
    return 1LL * (x1 - P.first) * (x1 - P.first) + 1LL * (y1 - P.second) * (y1 - P.second);
}

int main() {
    ios::sync_with_stdio(false);
    int N, X1, Y1, X2, Y2; cin >> N >> X1 >> Y1 >> X2 >> Y2;

    vector< pair<int, int> > P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i].first >> P[i].second;

    multiset<int64_t> distances;
    sort(P.begin(), P.end(), [&](pair<int, int> A, pair<int, int> B) {
        return dist(X1, Y1, A) < dist(X1, Y1, B);
    });

    distances.emplace(0);
    for (auto &p : P)
        distances.emplace(dist(X2, Y2, p));

    int64_t answer = *distances.rbegin();
    for (auto &p : P) {
        distances.erase(distances.find(dist(X2, Y2, p)));
        answer = min(answer, *distances.rbegin() + dist(X1, Y1, p));
    }

    cout << answer << "\n";
}