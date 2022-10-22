#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;

    vector<int> P(N);

    for (int i = 0; i < N; ++i)
        cin >> P[i];

    vector< vector< double> > present(N, vector<double>(N, 0)), future(N, vector<double>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            present[i][j] = 1;
    for (int k = 1; k <= K; ++k) {
        for (int i = 0; i < N; ++i) 
            for (int j = i + 1; j < N; ++j) {
                future[i][j] = 0;
                double multiplier = 2.0 / N / (N + 1);
                for (int p = 0; p < N; ++p)
                    for (int l = p; l < N; ++l) {
                        int newi = i;
                        int newj = j;
                        if (newi >= p && newi <= l)
                            newi = l - (newi - p);
                        if (newj >= p && newj <= l)
                            newj = l - (newj - p);
                        if (newi < newj)
                            future[i][j] += present[newi][newj] * multiplier;
                        else
                            future[i][j] += (1 - present[newj][newi]) * multiplier;
                    }
            }
        swap(future, present);
    }

    double answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (P[i] < P[j])
                answer += 1 - present[i][j];
            else
                answer += present[i][j];
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(12);
    cout << answer << "\n";
}