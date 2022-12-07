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

int x[26];
string s;
int a[100000], n;
map<pair<int, LL>, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    REP(i, 26) cin >> x[i];
    cin >> s;
    n = (int)s.length();
    REP(i, n) a[i] = s[i] - 'a';
    LL ans = 0, tot = 0;
    REP(i, n) {
        ans += cnt[mp(a[i], tot)];
        tot += x[a[i]];
        ++cnt[mp(a[i], tot)];
    }
    cout << ans << endl;
    return 0;
}