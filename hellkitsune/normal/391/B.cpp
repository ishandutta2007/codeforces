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
int d[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = (int)s.length();
    int ans = 0;
    REP(i, n) {
        d[i] = 1;
        for (int j = i - 1; j >= 0; j -= 2) if (s[j] == s[i])
            d[i] = max(d[i], d[j] + 1);
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}