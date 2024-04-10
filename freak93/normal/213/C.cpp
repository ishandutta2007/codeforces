#include <iostream>
#include <vector>

using namespace std;

const int inf = 0x3f3f3f3f;

int elem(vector< vector<int> > &A, int d, int e) {
    return A[e][d - e];
}

int main() {
    int N; cin >> N;

    vector< vector<int> > A(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];

    vector< vector<int> > now(N, vector<int>(N, -inf)), past = now;
    now[0][0] = A[0][0];
    for (int i = 1; i < 2 * N - 1; ++i) {
        swap(now, past);
        for (int j = 0; j < N; ++j)
            for (int k = j; k < N; ++k) {
                if (k > i || j > i) {
                    now[j][k] = -inf;
                    continue;
                }
                if (j <= i - N || k <= i - N) {
                    now[j][k] = -inf;
                    continue;
                }
                
                now[j][k] = past[j][k];
                if (j > 0)
                    now[j][k] = max(now[j][k], past[j - 1][k]);
                if (k > 0)
                    now[j][k] = max(now[j][k], past[j][k - 1]);
                if (j > 0 && k > 0)
                    now[j][k] = max(now[j][k], past[j - 1][k - 1]);
               
                now[j][k] += elem(A, i, j);
                if (k != j)
                    now[j][k] += elem(A, i, k);
            }
    }

    cout << now[N - 1][N - 1];
}