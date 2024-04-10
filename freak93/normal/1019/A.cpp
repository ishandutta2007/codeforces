#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;

    vector< pair<int, int> > people;
    vector<int> parties(M);
    for (int i = 0; i < N; ++i) {
        int party, cost; cin >> party >> cost;
        if (party != 1)
            people.emplace_back(cost, party - 1);
        ++parties[party - 1];
    }

    int64_t answer = numeric_limits<int64_t>::max();

    sort(people.begin(), people.end());
    vector<bool> temp(N, false);
    for (int votes = parties[0]; votes <= N; ++votes) {
        int extra = 0;
        fill(temp.begin(), temp.end(), false);

        int64_t aux = 0;
        for (int i = 0; i < int(people.size()); ++i)
            if (parties[people[i].second] >= votes) {
                aux += people[i].first;
                --parties[people[i].second];
                temp[i] = true;
                ++extra;
            }

        int need = max(0, votes - (parties[0] + extra));

        for (int i = 0; i < int(people.size()) && need > 0; ++i)
            if (!temp[i]) {
                aux += people[i].first;
                --parties[people[i].second];
                temp[i] = true;
                --need;
            }
        answer = min(answer, aux);

        for (int i = 0; i < int(people.size()); ++i)
            if (temp[i]) {
                ++parties[people[i].second];
            }
    }

    cout << answer << "\n";
}