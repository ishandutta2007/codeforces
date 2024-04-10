#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

long long f(pair<int, long long> F, int x) {
    return 1LL * x * F.first + F.second;
}

double time_swap(pair<int, long long> A, pair<int, long long> B) {
    // A.first * x + A.second == B.first * x + B.second
    // x * (A.first - B.first) = B.second - A.second
    return static_cast<double>(B.second - A.second) / (A.first - B.first);
}

int main() {
    cin.sync_with_stdio(false);

    int N, M, P; cin >> N >> M >> P;
    if (M <= P) {
        cout << "0\n";
        return 0;
    }

    vector<int> dis(N);
    dis[0] = 0;
    for (int i = 1; i < N; ++i) {
        cin >> dis[i];
        dis[i] += dis[i - 1];
    }

    vector<int> T(M);
    for (int i = 0; i < M; ++i) {
        int h, t; cin >> h >> t;
        T[i] = t - dis[h - 1];
    }

    sort(T.begin(), T.end());
    T.insert(T.begin(), 0);
    // dp[i][j] = the cost to get with i feeders the cats up to the jth
    // dp[i][j] = min of dp[i - 1][k] + (T[j] - T[k + 1]) + (T[j] - T[k + 2]) + ... + (T[j] - T[j])
    //                   = dp[i - 1][k] + T[j] * (j - k) + ST[j] - ST[k]
    //                   = ST[j] + T[j] * j - T[j] * k + (dp[i - 1][k] - ST[k)
    // function is -j * x + (past[j] - ST[j])
    vector<long long> ST(T.size());
    ST[0] = 0;
    for (int i = 1; i <= M; ++i)
        ST[i] = ST[i - 1] + T[i];

    vector<long long> present(M + 1), past;
    present[0] = 0;
    for (int i = 1; i <= M; ++i)
        present[i] = 1LL * T[i] * i - ST[i];

    for (int i = 2; i <= P; ++i) {
        swap(present, past);
        present = vector<long long>(M + 1);
        deque< pair<int, long long> > deque;
        for (int j = i; j <= M; ++j) {
            auto now = make_pair(-(j - 1), past[j - 1] + ST[j - 1]);
            while (deque.size() > 1 and time_swap(deque[deque.size() - 2], deque[deque.size() - 1]) > time_swap(deque[deque.size() - 1], now))
                deque.pop_back();
            deque.push_back(now);

            while (deque.size() > 1 and time_swap(deque[0], deque[1]) < T[j])
                deque.pop_front();

            present[j] = -ST[j] + 1LL * T[j] * j + f(deque.front(), T[j]);
        }
    }

    cout << present.back() << "\n";
}