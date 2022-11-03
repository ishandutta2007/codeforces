#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 14;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    string s;
    cin >> s;

    int ans = 0;
    int cur = 0;
    for(int i = 0; i < s.size(); i++) {
        if(i > 0 && s[i - 1] == s[i]) {
            ans++;
            if(i > 1 && s[i] == s[i - 2] || i + 2 < s.size() && s[i + 2] == s[i]) {
                s[i] = char(cur + 'A');
                cur = (cur + 1) % 26;
            } else if(i + 1 < s.size() && s[i - 1] == s[i + 1]) {
                s[i - 1] = char(cur + 'A');
                cur = (cur + 1) % 26;
            } else {
                s[i] = char(cur + 'A');
                cur = (cur + 1) % 26;
            }
        }

        if(i > 1 && s[i - 2] == s[i]) {
            ans++;
            s[i] = char(cur + 'A');
            cur = (cur + 1) % 26;
        }
    }
    cout << ans << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}