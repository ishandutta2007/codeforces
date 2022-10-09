#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    set<string> s;
    for (int i = 0; i < (int) a.size(); ++i) {
        string tmp;
        for (int j = i; j < (int) a.size(); ++j) {
            tmp += a[j];
            s.insert(tmp);
        }
    }
    int ans = a.size() + b.size();

    for (int i = 0; i < (int) b.size(); ++i) {
        string tmp;
        for (int j = i; j < (int) b.size(); ++j) {
            tmp += b[j];
            if (s.count(tmp)) {
                ans = min(ans, (int) a.size() + (int) b.size() - 2 * (j - i + 1));
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}