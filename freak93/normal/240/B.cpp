#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int inf = 0x3f3f3f3f;

int dp[205][40005][2];

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N; cin >> N;

    int X, Y; cin >> X >> Y;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 40005; ++j)
            dp[i][j][0] = dp[i][j][1] = inf;

    if (A[0] <= Y)
        dp[0][0][1] = 0;
    else
        dp[0][0][1] = inf;

    if (A[0] <= X)
        dp[0][A[0]][0] = 0;
    else
        dp[0][A[0]][0] = inf;

    int sum = A[0];
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (sum - j + A[i] <= Y) {
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1]);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] + min(A[i - 1], A[i]));
            }

            if (j + A[i] <= X) {
                dp[i][j + A[i]][0] = min(dp[i][j + A[i]][0], dp[i - 1][j][0]);
                dp[i][j + A[i]][0] = min(dp[i][j + A[i]][0], dp[i - 1][j][1] + min(A[i - 1], A[i]));
            }
        }
        sum += A[i];
    }

    int answer = inf;
    for (int i = 0; i < 40005; ++i) {
        answer = min(answer, dp[N - 1][i][0]);
        answer = min(answer, dp[N - 1][i][1]);
    }

    if (answer == inf)
        answer = -1;
    cout << answer;
}