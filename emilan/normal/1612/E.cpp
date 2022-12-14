#include <bits/stdc++.h>

using namespace std;

const int M = 2e5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[m, k] : a) cin >> m >> k;

    int j = 1;
    int best = 0;
    vector<int> ans;
    for (int i = 1; i <= 20; i++) {
        array<pair<int, int>, M> score{};
        for (int m = 0; m < M; m++) {
            score[m].second = m;
        }
        for (auto [m, k] : a) {
            score[--m].first += min(i, k);
        }

        sort(score.rbegin(), score.rend());

        int pts = 0;
        vector<int> msg;
        for (int m = 0; m < i; m++) {
            if (score[m].first != 0) {
                pts += score[m].first;
                msg.push_back(score[m].second);
            }
        }

        // pts / i > best / j
        if (pts * j > best * i) {
            j = i;
            best = pts;
            ans = msg;
        }
    }

    int m = ans.size();
    cout << m << "\n";
    for (int i = 0; i < m; i++) {
        cout << ans[i] + 1 << " \n"[i == m - 1];
    }
}