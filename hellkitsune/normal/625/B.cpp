#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    int ans = 0;
    int n = (int)s.length();
    int m = (int)t.length();
    REP(i, n - m + 1) {
        if (s.substr(i, m) == t) {
            s[i + m - 1] = '#';
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}