#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;

int main() {
    cin >> n >> s;
    int ans = 0;
    int cur = 0;
    for (char c : s) {
        if (c == 'x') {
            ++cur;
        } else {
            cur = 0;
        }
        if (cur > 2) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}