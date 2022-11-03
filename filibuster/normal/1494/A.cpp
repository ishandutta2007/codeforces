#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;

/*

*/

void solve() {
    string s;
    cin >> s;

    int n = s.length();

    bool ans = false;
    for(int mask = 0; mask< 8; mask++) {
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            if((1 << (s[i] - 'A')) & mask) {
                a[i] = 1;
            } else {
                a[i] = -1;
            }
        }

        int cur = 0;
        bool res = true;
        for(int i = 0; i < n; i++) {
            cur += a[i];
            if(cur < 0)
                res = false;
        }
        if(cur != 0)
            res = false;
        ans |= res;
    }

    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}