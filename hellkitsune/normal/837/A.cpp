#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;

int main() {
    cin >> n;
    int len = 0;
    int ans = 0;
    while (len < n) {
        if (len > 0) ++len;
        string s;
        cin >> s;
        len += (int)s.size();
        int cur = 0;
        for (char c : s) if (c >= 'A' && c <= 'Z') {
            ++cur;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}