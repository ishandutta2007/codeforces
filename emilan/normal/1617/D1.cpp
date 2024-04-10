#include <bits/stdc++.h>

using namespace std;

int query(int i, int j, int k) {
    cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

void answer(const vector<int> &v) {
    cout << "! " << v.size();
    for (int i : v) cout << ' ' << i + 1;
    cout << endl;
}

void solve() {
    int n;
    cin >> n;

    int fst = query(0, 1, 2);
    int s = -1;
    for (int i = 1; i < n - 2; i++) {
        if (query(i, i + 1, i + 2) != fst) {
            s = i;
            break;
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) if (i != s && i != s + 1) {
        if (query(s, s + 1, i) == 0) ans.push_back(i);
    }

    if (query(s - 1, s + 2, s) == 0) ans.push_back(s);
    else ans.push_back(s + 1);

    answer(ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}