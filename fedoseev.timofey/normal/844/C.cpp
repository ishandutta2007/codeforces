#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n + 1), used(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector <int> p(n + 1);
    for (int i = 1; i <= n; ++i) p[i] = i;
    sort(p.begin() + 1, p.end(), [&](int first, int other) {
        return a[first] < a[other];
    });
    vector <vector <int>> ans(1);
    for (int i = 1; i <= n; ++i) {
        if (used[i]) continue;
        ans.back().push_back(i);
        used[i] = 1;
        int cur = p[i];
        while (cur != i) {
            used[cur] = 1;
            ans.back().push_back(cur);
            cur = p[cur];
        }
        ans.push_back({});
    }
    ans.pop_back();
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].size() << " ";
        for (auto e : ans[i]) {
            cout << e << " ";
        }
        cout << endl;
    }
}