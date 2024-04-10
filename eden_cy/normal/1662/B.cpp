#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, len[3];
int cnt[3][26];
vector<pii> match;
vector<pii> pl;
vector<int> fin[3];
inline int Fetch(int d) {
    for (int i = 0; i < 26; ++i) if (cnt[d][i]) {
        --cnt[d][i];
        --len[d];
        return i;
    }
    return 0;
}
inline void MatchFin() {
    for (int d = 0; d < 3; ++d) {
        while (!fin[d].empty()) {
            pl.emplace_back(Fetch(d), fin[d].back());
            fin[d].pop_back();
        }
    }
}
int main() {
    for (int d = 0; d < 3; ++d) {
        static string s;
        cin >> s;
        for (auto c: s) ++cnt[d][c - 'A'];
        len[d] = s.size();
    }
    for (int i = 0; i < 26; ++i) {
        pii cho[3] = {{cnt[0][i], 0}, {cnt[1][i], 1}, {cnt[2][i], 2}};
        while (1) {
            sort(cho, cho + 3, greater<pii>());
            if (cho[1].first == 0) break;
            --cho[0].first; --cho[1].first;
            match.emplace_back(i, cho[2].second);
        }
    }
    while (!match.empty()) {
        bool flag = 0;
        for (int d = 0; d < 3; ++d) if (len[d] <= (int)fin[d].size()) {
            flag = 1;
        }
        if (flag) break;
        auto [ch, x] = match.back(); match.pop_back();
        // printf("Match %c %d\n", ch + 'A', x);
        for (int d = 0; d < 3; ++d) --cnt[d][ch], --len[d];
        ++cnt[x][ch], ++len[x];
        fin[x].push_back(ch);
    }
    MatchFin();
    pii cho[3] = {{len[0], 0}, {len[1], 1}, {len[2], 2}};
    while (1) {
        sort(cho, cho + 3, greater<pii>());
        if (cho[0].first == 0) break;
        --cho[0].first; --cho[1].first;
        pl.emplace_back(Fetch(cho[0].second), Fetch(cho[1].second));
    }
    cout << pl.size() << endl;
    for (auto [x, y]: pl) printf("%c%c\n", 'A' + x, 'A' + y);
    return 0;
}