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

int a[3000], b[3000];
vector<PII> ans;
int n;

int main() {
    cin >> n;
    REP(i, n) cin >> a[i], b[i] = a[i];
    sort(b, b + n);
    REP(i, n) for (int j = i; j < n; ++j) if (a[j] == b[i]) {
        if (j != i) {
            swap(a[i], a[j]);
            ans.pb(mp(i, j));
        }
        break;
    }
    cout << (int)ans.size() << '\n';
    REP(i, ans.size())
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}