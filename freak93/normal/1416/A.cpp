#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        vector< vector<int> > positions(N + 1);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            positions[A[i]].push_back(i);
        }

        vector<int> best(N + 1, N + 1);
        for (int i = 1; i <= N; ++i) {
            int last = -1;
            int maxdistance = 0;
            for (auto &p : positions[i]) {
                maxdistance = max(maxdistance, p - last);
                last = p;
            }
            maxdistance = max(maxdistance, N - last);
            if (last != -1)
                best[maxdistance] = min(best[maxdistance], i);
        }
        for (int i = 1; i <= N; ++i) {
            best[i] = min(best[i], best[i - 1]);
            if (best[i] == N + 1)
                cout << "-1 ";
            else
                cout << best[i] << " ";
        }
        cout << "\n";
    }
}