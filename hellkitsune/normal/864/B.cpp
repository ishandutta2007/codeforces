#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;
set<char> se;

int main() {
    cin >> n >> s;
    int ans = 0;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            se.clear();
        } else {
            se.insert(c);
            ans = max(ans, (int)se.size());
        }
    }
    cout << ans << endl;
    return 0;
}