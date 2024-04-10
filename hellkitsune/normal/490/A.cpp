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
vector<int> a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        int x;
        cin >> x;
        if (x == 1) a.pb(i + 1);
        else if (x == 2) b.pb(i + 1);
        else c.pb(i + 1);
    }
    int cnt = (int)min(min(a.size(), b.size()), c.size());
    cout << cnt << '\n';
    REP(i, cnt)
        cout << a[i] << ' ' << b[i] << ' ' << c[i] << '\n';
    return 0;
}