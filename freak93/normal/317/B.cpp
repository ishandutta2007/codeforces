#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

const int kMaxN = 80;

int main() {
    int N, T; cin >> N >> T;

    vector< vector<int> > A(kMaxN, vector<int>(kMaxN, 0));
    A[0][0] = N;

    do {
        vector< vector<int> > B(kMaxN, vector<int>(kMaxN, 0));

        int maximum = 0;
        array<int, 4> dx = {-1, 0, 1, 0};
        array<int, 4> dy = {0, -1, 0, 1};

        for (int i = 0; i < kMaxN; ++i)
            for (int j = 0; j < kMaxN; ++j) {
                maximum = max(maximum, A[i][j]);
                B[i][j] += A[i][j] % 4;

                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0)
                        x = -x;
                    if (y < 0)
                        y = -y;

                    if (x >= kMaxN or y >= kMaxN)
                        continue;
                    B[i][j] += A[x][y] / 4;
                }
            }
        swap(A, B);
        if (maximum < 4)
            break;
    } while (true);

    while (T--) {
        int X, Y; cin >> X >> Y;
        if (X < 0)
            X = -X;
        if (Y < 0)
            Y = -Y;

        if (X < kMaxN and Y < kMaxN)
            cout << A[X][Y] << "\n";
        else
            cout << 0 << "\n";
    }
}