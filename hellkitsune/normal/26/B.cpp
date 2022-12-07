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

int op = 0, ans = 0;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (char c : s) if (c == '(')
        ++op, ++ans;
    else if (op > 0)
        --op, ++ans;
    ans -= op;
    cout << ans << '\n';
    return 0;
}