#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X; cin >> N >> X;

    array<vector< pair<int, int> >, 2> C;
    for (int i = 0; i < N; ++i) {
        int t, h, m; cin >> t >> h >> m;
        C[t].emplace_back(h, m);
    }

    int answer = 0;
    for (int i = 0; i < 2; ++i) {
        auto copy = C;

        int aux;
        int jump = X;
        for (aux = 0; ; ++aux) {
            int best = 0, where = -1;
            for (int j = 0; j < int(C[aux % 2].size()); ++j)
                if (C[aux % 2][j].first <= jump && C[aux % 2][j].second > best) {
                    best = C[aux % 2][j].second;
                    where = j;
                }

            if (where == -1)
                break;
            C[aux % 2].erase(C[aux % 2].begin() + where);
            jump += best;
        }

        answer = max(answer, aux);
        C = copy;
        swap(C[0], C[1]);
    }

    cout << answer << "\n";
}