#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<char> p(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p[i] = (char)x;
    }
    vector<char> maxP(n + 1);
    maxP[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        maxP[i] = max(maxP[i + 1], p[i]);
    }
    int ans = 0;
    vector<vector<bool>> was(n + 1, vector<bool>(n + 1));
    queue<tuple<int, int, int>> q; // first/second fool/time
    q.emplace(0, 1, 0);
    while (!q.empty()) {
        auto [first, second, moment] = q.front();
        second = min(second, n);
        q.pop();
        if (was[first][second] || moment > k) continue;
        was[first][second] = true;
        ++ans;
        if (second == n) continue;
        bool canFirstSurvive = maxP[second] < 100;
        bool canFirstDie = maxP[second] > 0;
        bool canSecondSurvive = p[first] < 100;
        bool canSecondDie = p[first] > 0;
        if (canFirstSurvive && canSecondDie)
            q.emplace(first, second + 1, moment + 1);
        if (canFirstDie && canSecondSurvive)
            q.emplace(second, second + 1, moment + 1);
        if (canFirstDie && canSecondDie)
            q.emplace(second + 1, second + 2, moment + 1);
    }
    cout << ans << endl;
}