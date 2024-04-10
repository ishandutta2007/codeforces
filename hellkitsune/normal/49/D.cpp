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
typedef long long LL;
typedef pair<int, int> PII;

int n, ans = 1234567;
string s;

void solve(string s) {
    int cur = 0;
    REP(i, n) if (i % 2 == s[i] - '0') {
        ++cur;
    }
    ans = min(ans, cur);
}

int main() {
    cin >> n >> s;
    solve(s);
    REP(i, n) s[i] = (s[i] == '1') ? '0' : '1';
    solve(s);
    cout << ans << endl;
    return 0;
}