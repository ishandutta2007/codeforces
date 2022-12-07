#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;
vector<string> ans;

bool con(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    string cur;
    for (char c : s) {
        int sz = (int)cur.size();
        if (sz >= 2 && con(cur[sz - 1]) && con(cur[sz - 2]) && con(c)) {
            if (cur[sz - 1] != c || cur[sz - 2] != c) {
                ans.pb(cur);
                cur.clear();
            }
        }
        cur.pb(c);
    }
    if (!cur.empty()) {
        ans.pb(cur);
    }
    forn(i, (int)ans.size() - 1) {
        cout << ans[i] << ' ';
    }
    cout << ans.back() << endl;
    return 0;
}