#include <bits/stdc++.h>
using namespace std;

int n, K;
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> K;
    auto ask = [&](int x, int y) {
        cout << "1 " << x << " " << y << endl;
        string s; cin >> s;
        return s;
    };
    vector<int> ans;
    auto chk = [&](int l) {
        if (l > 1 && ask(l, l - 1) == "NIE") return;
        if (l < n && ask(l, l + 1) == "NIE") return;
        ans.push_back(l);
    };
    int need = 1;
    function<void(int, int)> solve = [&](int l, int r) {
        if (l > r || ans.size() == need) return;
        if (l == r) { chk(l); return; }
        int mid = (l + r) / 2;
        if (ask(mid, mid + 1) == "TAK") solve(l, mid);
        else solve(mid + 1, r);
    };
    solve(1, n), assert(!ans.empty());
    need = 2, solve(1, ans[0] - 1), solve(ans[0] + 1, n);
    assert(ans.size() == 2);
    cout << "2 " << ans[0] << " " << ans[1] << endl;
    return 0;
}