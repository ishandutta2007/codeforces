#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N, M; cin >> N >> M;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        vector< vector<int> > ends(N);
        vector<int> begins(N, 0);
        for (int i = 0; i < M; ++i) {
            int x, y; cin >> x >> y;
            --x; --y;
            ends[y].emplace_back(x);
            ++begins[x];
        }

        multiset<int> open;
        map<int, vector<int> > pos;
        int begin = N + 1, end = -1;
        vector< pair<int, int> > pairs;
        for (int i = 0; i < N; ++i) {
            pos[A[i]].push_back(i);
            for (int j = 0; j < begins[i]; ++j)
                open.emplace(i);

            if (open.empty())
                continue;

            int limit = *open.begin();
            auto &p = pos[A[i]];
            int K = p.size();
            auto idx = lower_bound(p.begin(), p.end(), limit) - p.begin();

            if (idx + 2 < K) {
                begin = min(begin, p[idx + 1]);
                end = max(end, p[K - 2]);
            }
            if (idx + 1 < K)
                pairs.emplace_back(p[idx], p.back());

            for (auto &b : ends[i])
                open.erase(open.find(b));
        }

        if (pairs.empty()) {
            cout << 0 << "\n";
            continue;
        }

        vector< vector<int> > mates(N);
        multiset<int> rightmost;
        for (auto &p : pairs) {
            mates[p.first].push_back(p.second);
            rightmost.emplace(p.first);
        }

        int answer = N + 1;
        for (int i = 0; i < N; ++i) {
            int b = min(begin, min(i, *rightmost.begin()));
            int e = max(end, *rightmost.rbegin());

            answer = min(answer, e - b + 1);
            for (auto &m : mates[i]) {
                rightmost.emplace(m);
                rightmost.erase(rightmost.find(i));
            }
        }
        cout << answer << "\n";
    }
}