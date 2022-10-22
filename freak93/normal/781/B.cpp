#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector< pair<string, string> > S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i].first >> S[i].second;

    map<string, vector<int> > first;
    for (int i = 0; i < N; ++i)
        first[S[i].first.substr(0, 3)].push_back(i);

    vector<string> answer(N);
    queue<string> Q;
    set<string> have;
    for (auto &p : first)
        if (p.second.size() > 1)
            Q.push(p.first);
    while (!Q.empty()) {
        string common = Q.front();
        Q.pop();

        // all of them ned their second name
        for (auto &index : first[common]) {
            if (index == -1)
                continue;
            answer[index] = S[index].first.substr(0, 2);
            answer[index] += S[index].second[0];
            if (have.count(answer[index])) {
                cout << "NO\n";
                return 0;
            }
            have.emplace(answer[index]);
            if (answer[index] != common) {
                auto &vec = first[answer[index]];
                vec.push_back(-1);
                if (vec.size() == 2)
                    Q.push(answer[index]);
            }
        }
    }
    for (int i = 0; i < N; ++i)
        if (answer[i] == "")
            answer[i] = S[i].first.substr(0, 3);
    cout << "YES\n";
    for (auto &s : answer)
         cout << s << "\n";
}