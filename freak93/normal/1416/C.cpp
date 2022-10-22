#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class It>
void solve(It begin, It end, int bit, vector< pair<int64_t, int64_t> > &cost) {
    if (bit < 0 || end - begin <= 1)
        return;
    int zeros = 0;
    int ones = 0;
    for (auto it = begin; it != end; ++it) {
        int now = ((*it & (1 << bit)) >> bit);
        if (now == 1) {
            cost[bit].second += zeros;
            ++ones;
        } else {
            cost[bit].first += ones;
            ++zeros;
        }
    }
    auto mid = stable_partition(begin, end, [=](int x) {
        return (1 << bit) & x;
    });
    solve(begin, mid, bit - 1, cost);
    solve(mid, end, bit - 1, cost);
}

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector< pair<int64_t, int64_t> > cost(32);
    solve(A.begin(), A.end(), 30, cost);

    int64_t total = 0;
    int answer = 0;
    for (int i = 0; i < 31; ++i)
        if (cost[i].first <= cost[i].second)
            total += cost[i].first;
        else {
            total += cost[i].second;
            answer += (1 << i);
        }

    cout << total << " " << answer << "\n";
}