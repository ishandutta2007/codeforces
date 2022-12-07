#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s[100];

int main() {
    cin >> n;
    REP(i, n) cin >> s[i];
    int ans = 0;
    REP(i, n) {
        int cnt = 0;
        REP(j, n) cnt += s[i][j] == 'C';
        ans += cnt * (cnt - 1) / 2;
    }
    REP(i, n) {
        int cnt = 0;
        REP(j, n) cnt += s[j][i] == 'C';
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}