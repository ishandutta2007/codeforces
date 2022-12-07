#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, s;
string ans;

int main() {
    cin >> n >> s;
    if (n == 1) {
        if (s >= 10) cout << "-1 -1\n";
        else cout << s << ' ' << s << '\n';
        return 0;
    }
    if (s < 1 || s > 9 * n) {
        cout << "-1 -1\n";
        return 0;
    }
    int sum = s;
    REP(i, n - 1) {
        int dig = min(s - 1, 9);
        s -= dig;
        ans += char('0' + dig);
    }
    ans += char('0' + s);
    reverse(ans.begin(), ans.end());
    cout << ans << ' ';
    ans = "";
    s = sum;
    REP(i, n) {
        int dig = min(s, 9);
        s -= dig;
        ans += char('0' + dig);
    }
    cout << ans << '\n';
    return 0;
}