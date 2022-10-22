#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;

    vector<int> V(2 * N - 1);
    int negative = 0;
    for (int i = 0; i < 2 * N - 1; ++i) {
        cin >> V[i];
        if (V[i] < 0) {
            negative++;
            V[i] = -V[i];
        }
    }

    queue<int> Q;
    Q.push(negative);
    vector<int> used(2 * N - 1, 0);
    used[negative] = 1;

    int answer = 2 * N - 1;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        answer = min(answer, x);

        for (int i = 0; i <= x and i <= N; ++i)
            if (N - i <= 2 * N - x - 1) {
                int y = x - i + N - i;
                if (used[y] == 0) {
                    used[y] = 1;
                    Q.push(y);
                }
            }
    }

    int sum = 0;
    sort(V.begin(), V.end());
    for (int i = 0; i < 2 * N - 1; ++i)
        if (i < answer)
            sum -= V[i];
        else
            sum += V[i];
    cout << sum << "\n";
}