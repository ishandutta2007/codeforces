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
    n = (int)s.length();
    int ans = 0;
    int cnt = 1;
    char cur = 'z';
    REP(i, n) if (s[i] == cur)
        ++cnt;
    else {
        if (cnt % 2 == 0) ++ans;
        cnt = 1;
        cur = s[i];
    }
    if (cnt % 2 == 0) ++ans;
    cout << ans << endl;
    return 0;
}