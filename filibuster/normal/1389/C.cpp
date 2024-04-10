#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*
5 10
99.99

1
5 4 1
1 5 4 3 2
*/

void solve() {
    string s;
    cin >> s;

    int ans = s.length();
    for(char c1 = '0'; c1 <= '9'; c1++)
        for(char c2 = '0'; c2 <= '9'; c2++) {
            int cur = 0;
            for(int i = 0; i < s.length(); i++) {
                if(cur % 2 == 0) {
                    if(s[i] == c1) {
                        cur++;

                    } else {

                    }
                } else {
                    if(s[i] == c2) {
                        cur++;
                    }
                }
            }

            ans = min(ans, int(s.length()) - cur + cur % 2);
//            cout << int(s.length()) - cur << ' ' << c1 << ' ' << c2 << endl;
        }

    map<char, int> mp;
    for(auto c : s)
        mp[c]++;

    int mx = 0;
    for(auto p : mp)
        mx = max(mx, p.s);

    ans = min(ans, int(s.length()) - mx);

    cout << ans << endl;
}

//int s[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}