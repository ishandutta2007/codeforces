#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N, K; cin >> N >> K;

        map<int, int> count;
        map<int, int> deleted;
        for (int i = 0; i < N; ++i) {
            int x; cin >> x;
            ++count[x];
        }

        set< pair<int, int> > have, dropped;
        for (auto &p : count)
            have.emplace(p.second, p.first);

        int total_deleted = 0;
        int answer = N;
        int missing_slots = 0;
        for (int mex = 0; mex <= N; ++mex) {
            if (K < missing_slots)
                break;

            while (!have.empty() && have.begin()->first + total_deleted <= K) {
                total_deleted += have.begin()->first;
                dropped.emplace(*have.begin());
                have.erase(have.begin());
            }

            answer = min(answer, int(have.size()));

            if (!count.count(mex)) {
                ++missing_slots;
                continue;
            }
            int y = count[mex];
            if (have.count(make_pair(y, mex)))
                have.erase(make_pair(y, mex));
            else {
                total_deleted -= y;
                dropped.erase(make_pair(y, mex));
            }
        }
        cout << answer << "\n";
    }
}