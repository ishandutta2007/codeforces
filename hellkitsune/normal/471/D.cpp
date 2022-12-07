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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, w, x;
basic_string<int> a, b;
int p[500000];
int ans = 0;

void P(basic_string<int> &s, int aLen) {
    int len = (int)s.length();
    p[0] = 0;
    for (int i = 1; i < len; ++i) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            ++j;
        p[i] = j;
        if (i > aLen && p[i] == aLen) ++ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> w, --n, --w;
    if (w > n) {
        cout << 0 << endl;
        return 0;
    }
    if (w == 0) {
        cout << n + 1 << endl;
        return 0;
    }
    cin >> x;
    REP(i, n) {
        int y;
        cin >> y;
        a += y - x;
        x = y;
    }
    cin >> x;
    REP(i, w) {
        int y;
        cin >> y;
        b += y - x;
        x = y;
    }
    int sz = (int)b.length();
    b += 2000000007 + a;
    P(b, sz);
    cout << ans << endl;
    return 0;
}