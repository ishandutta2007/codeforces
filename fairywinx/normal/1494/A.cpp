#include <algorithm>
#include <iostream>
#include <vector>

#define all(a) a.begin(), a.end()

using namespace std;

bool solve(string s) {
    int bal = 0;
    for (char i : s) {
        if (i == '(')
            bal++;
        else
            bal--;
        if (bal < 0)
            return false;
    }
    return bal == 0;
}

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < (1 << 3); ++i) {
        string res;
        for (int j = 0; j < (int) s.size(); ++j) {
            if ((1 << (s[j] - 'a')) & i)
                res += '(';
            else
                res += ')';
        }
        if (solve(res)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}