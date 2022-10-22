#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int M; cin >> M;

    vector< pair<int, int> > V;
    for (int i = 0; i < M; ++i) {
        int type; cin >> type;
        if (type == 1) {
            int value; cin >> value;
            V.push_back({0, value});
        } else {
            int L, C; cin >> L >> C;
            V.push_back({L, C});
        }
    }

    vector<int64_t> sum(M, 0);
    sum[0] = 1;
    for (int i = 1; i < M; ++i)
        if (V[i].first != 0)
            sum[i] = sum[i - 1] + 1LL * V[i].first * V[i].second;
        else
            sum[i] = sum[i - 1] + 1;

    vector<int> prefix(min<int64_t>(100000, sum.back()));
    int K = 0;
    for (int i = 0; i < M && K < int(prefix.size()); ++i) {
        if (V[i].first == 0)
            prefix[K++] = V[i].second;
        else {
            for (int c = 0; c < V[i].second && K < int(prefix.size()); ++c)
                for (int l = 0; l < V[i].first && K < int(prefix.size()); ++l)
                    prefix[K++] = prefix[l];
        }
    }

    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        int64_t position; cin >> position;
        int group = lower_bound(sum.begin(), sum.end(), position) - sum.begin();
        position -= (group > 0 ? sum[group - 1] : 0);
        if (V[group].first == 0)
            cout << V[group].second << " ";
        else {
            --position;
            position %= V[group].first;
            cout << prefix[position] << " ";
        }
    }
}