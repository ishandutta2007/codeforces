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

int n;
string s;
int cnt[26] = {};
int ans = 0;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    REP(i, n) ++cnt[s[i] - 'A'];
    int mx = cnt[0];
    REP(i, 26) mx = max(mx, cnt[i]);
    REP(i, 26) if (cnt[i] == mx)
        ++ans;
    int mul = ans;
    for (int i = 1; i < n; ++i)
        ans = ((LL)ans * mul) % MOD;
    cout << ans << endl;
    return 0;
}