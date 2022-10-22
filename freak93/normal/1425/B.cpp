#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int kModulo = 1000 * 1000 * 1000 + 7;

int main() {
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    vector< vector<int> > edges(N);
    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        edges[x - 1].emplace_back(y - 1);
        edges[y - 1].emplace_back(x - 1);
    }

    vector<int> length;
    vector<bool> used(N, false);
    for (auto &next : edges[0]) {
        if (used[next])
            continue;
        int now = next;
        int old = 0;
        int aux = 1;
        while (now != 0) {
            used[now] = true;
            int k = 0;
            if (edges[now][0] == old)
                ++k;
            old = now;
            now = edges[now][k];
            ++aux;
        }
        length.push_back(aux);
    }

    N = length.size();
    vector< vector<int> > suffix(N + 1, vector<int>(2 * M + 1, 0)), suffix_total = suffix;

    suffix[N][M] = 1;
    suffix_total[N][M] = 1; 
    auto extend = [&](const vector<int> &prev, vector<int> &next, int value, bool use_old = true) {
        for (int i = 0; i <= 2 * M; ++i) {
            if (use_old)
                next[i] = prev[i];
            else 
                next[i] = 0;

            next[i] += (i >= value ? prev[i - value] : 0);
            next[i] -= (next[i] >= kModulo ? kModulo : 0);

            next[i] += (i <= 2 * M - value ? prev[i + value] : 0);
            next[i] -= (next[i] >= kModulo ? kModulo : 0);
        }
    };

    for (int i = N - 1; i >= 0; --i) {
        extend(suffix[i + 1], suffix[i], length[i]);
        extend(suffix_total[i + 1], suffix_total[i], length[i], false);
    }

    int answer = 0;
    vector<int> partial_sum(2 * M + 1);

    vector<int> prefix[2], prefix_total[2];
    prefix[0] = prefix[1] = prefix_total[0] = prefix_total[1] = vector<int>(2 * M + 1, 0);
    prefix[0][M] = prefix_total[0][M] = 1;

    for (int i = 0; i < N; ++i) {
        extend(prefix[i % 2], prefix[1 - i % 2], length[i]);
        extend(prefix_total[i % 2], prefix_total[1 - i % 2], length[i], false);

        partial_sum[0] = prefix[i % 2][0];
        for (int j = 1; j <= 2 * M; ++j) {
            partial_sum[j] = partial_sum[j - 1] + prefix[i % 2][j];
            partial_sum[j] -= (partial_sum[j] >= kModulo ? kModulo : 0);
        }
        int L = length[i];
        for (int j = -M; j <= M; ++j) {
            int now = suffix[i + 1][j + M];
            if (now == 0)
                continue;
            // we want j - L + 2 -> j + L - 2
            int other = (j + L - 2 <= M ? partial_sum[j + M + L - 2] : partial_sum[2 * M]);
            other -= (j - L + 1 >= -M ? partial_sum[j + M - L + 1] : 0);
            answer = (answer + 2LL * now * (other + kModulo)) % kModulo;
        }

        for (int j = -M; j <= M; ++j) {
            int now = suffix_total[i + 1][j + M];
            if (now == 0)
                continue;

            int other = (j + L - 1 <= M ? prefix_total[i % 2][j + M + L - 1] : 0);
            other += (j - L + 1 >= -M ? prefix_total[i % 2][j + M - L + 1] : 0);
            answer = (answer + 2LL * now * other) % kModulo;
        }
    }

    answer = (answer + prefix_total[N % 2][M]) % kModulo;
    cout << answer << "\n";
}