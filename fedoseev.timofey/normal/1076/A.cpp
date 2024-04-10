#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] > s[i + 1]) {
            s.erase(s.begin() + i);
            break;
        }
    }
    if (s.size() == n) s.pop_back();
    cout << s << '\n';
}