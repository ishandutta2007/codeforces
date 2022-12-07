#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;
int a[5001], b[5001];

int main() {
    cin >> s;
    n = (int)s.size();
    forn(i, n) {
        a[i + 1] = a[i] + (s[i] == 'a');
        b[i + 1] = b[i] + (s[i] == 'b');
    }
    int ans = 0;
    forn(j, n + 1) forn(i, j + 1) {
        int cur = a[i];
        cur += b[j] - b[i];
        cur += a[n] - a[j];
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}