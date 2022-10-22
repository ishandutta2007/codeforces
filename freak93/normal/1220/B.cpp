#include <iostream>
#include <vector>

using namespace std;

int64_t sqrti(int64_t x) {
    int64_t step;
    for (step = 1; step * step < x; step <<= 1);

    int64_t answer = 0;
    for (; step; step >>= 1)
        if ((answer + step) * (answer + step) <= x)
            answer += step;
    return answer;
}

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector< vector<int> > V(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> V[i][j];

    vector<int> answer(N);
    answer[0] = sqrti(1LL * V[0][1] * V[0][2] / V[1][2]);
    for (int i = 1; i < N; ++i)
        answer[i] = V[0][i] / answer[0];

    for (int i = 0; i < N; ++i)
        cout << answer[i] << " ";
    cout << "\n";
}