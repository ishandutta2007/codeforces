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

string s;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int ans = 0;
    n = (int)s.length();
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        int ii = i, jj = j;
        while (ii < n && jj < n && s[ii] == s[jj])
            ++ii, ++jj;
        ans = max(ans, ii - i);
    }
    cout << ans << endl;
    return 0;
}