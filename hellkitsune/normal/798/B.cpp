#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n;
string s[50];

string rot(string s, int cnt) {
    return s.substr(cnt) + s.substr(0, cnt);
}

int main() {
    cin >> n;
    forn(i, n) cin >> s[i];
    int len = s[0].size();
    int ans = INF;
    forn(i, len) {
        string t = rot(s[0], i);
        int cur = i;
        for (int j = 1; j < n; ++j) {
            bool ok = false;
            forn(k, len) {
                if (rot(s[j], k) == t) {
                    ok = true;
                    cur += k;
                    break;
                }
            }
            if (!ok) {
                cout << -1 << endl;
                return 0;
            }
        }
        ans = min(ans, cur);
    }
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}