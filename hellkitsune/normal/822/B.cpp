#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
string s, t;

int main() {
    cin >> n >> m >> s >> t;
    int ans = 1234;
    int pos = -1;
    forn(i, m - n + 1) {
        int cur = 0;
        forn(j, n) {
            cur += s[j] != t[i + j];
        }
        if (cur < ans) {
            ans = cur;
            pos = i;
        }
    }
    cout << ans << endl;
    forn(i, n) if (s[i] != t[pos + i]) {
        printf("%d ", i + 1);
    }
    puts("");
    return 0;
}