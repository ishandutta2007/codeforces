#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<pii> ans;

void make_char(string& s, int idx, char c) {
    for (int i = idx; s[idx]; ++i) {
        if (s[i] == c) {
            if (i != idx)
                ans.emplace_back(idx, i);
            reverse(s.begin() + idx, s.begin() + i + 1);
            return;
        }
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        ans.clear();
        for (int i = 0; i < k - 1; ++i) {
            make_char(s, 2 * i, '(');
            make_char(s, 2 * i + 1, ')');
        }
        int leftover = (n - 2 * (k - 1)) / 2;
        int idx = 2 * (k - 1);
        for (int i = 0; i < leftover; ++i)
            make_char(s, idx + i, '(');
        for (int i = 0; i < leftover; ++i)
            make_char(s, idx + leftover + i, ')');
        cout << ans.size() << endl;
        for (auto& p : ans) {
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
    }
}