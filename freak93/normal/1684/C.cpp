#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N, M; cin >> N >> M;

        vector< vector<int> > V(M, vector<int>(N));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> V[j][i];

        auto copy = V;
        bool can = true;
        sort(copy.begin(), copy.end());
        for (int i = 1; i < M; ++i) {
            for (int j = 0; j < N; ++j)
                if (copy[i - 1][j] > copy[i][j])
                    can = false;
        }
        int X = -1, Y = -1;
        for (int i = 0; i < M; ++i)
            if (copy[i] != V[i]) {
                if (X == -1)
                    X = i;
                else if (Y == -1)
                    Y = i;
                else 
                    can = false;
            }
        if (!can) {
            cout << "-1\n";
        } else if (Y == -1) {
            cout << "1 1\n";
        } else {
            cout << X + 1 << " " << Y + 1 << "\n";
        }
    }
}