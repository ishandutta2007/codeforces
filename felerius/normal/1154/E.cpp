#include <bits/stdc++.h>


using namespace std;

int main() {
    size_t n, k;
    cin >> n >> k;

    list<pair<int, size_t>> l;
    vector<decltype(l)::iterator> it(n);
    for (size_t i = 0; i < n; ++i) {
        int j;
        cin >> j;
        l.emplace_back(j - 1, i);
        it[j - 1] = prev(end(l));
    }

    vector<uint8_t> team(n);
    int best = n - 1;
    auto curteam = 1;
    while (!l.empty()) {
        while (it[best] == l.end()) {
            best--;
        }

        auto beg = it[best];
        auto end = it[best];
        for (size_t i = 0; i < k && beg != l.begin(); ++i) {
            --beg;
        }
        for (size_t i = 0; i < k + 1 && end != l.end(); ++i) {
            end++;
        }

        for (auto i = beg; i != end; ++i) {
            it[i->first] = l.end();
            team[i->second] = curteam;
        }

        l.erase(beg, end);
        curteam = 3 - curteam;
    }

    for (auto t : team) {
        cout << (char)(t + '0');
    }

    cout << '\n';
}