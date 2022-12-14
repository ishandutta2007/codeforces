#include <bits/stdc++.h>

using namespace std;

vector<int> pos[128];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s;
    cin >> s;
    for (int i = 0; i < int(s.size()); i++) {
        pos[s[i]].push_back(i);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (l == r || s[l] != s[r]) cout << "Yes";
        else {
            int cnt = 0;
            for (int i = 'a'; i <= 'z'; i++) {
                auto lb = lower_bound(pos[i].begin(), pos[i].end(), l);
                if (lb != pos[i].end() && *lb <= r) cnt++;
            }

            cout << (cnt >= 3 ? "Yes" : "No");
        }

        cout << '\n';
    }
}