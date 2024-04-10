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
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

char s[5000005];
int d1[5000005], d2[5000005];
int d[5000005] = {};
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = (i > r ? 1 : min(d1[l + r - i], r - i));
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) ++k;
        d1[i] = k--;
        if (i + k > r)
            l = i - k, r = i + k;
    }
    l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1)) + 1;
        while (i + k - 1 < n && i - k >= 0 && s[i + k - 1] == s[i - k]) ++k;
        d2[i] = --k;
        if (i + k - 1 > r)
            l = i - k, r = i + k - 1;
    }
    d[0] = 1;
    LL ans = 1;
    for (int i = 1; i < n; ++i) {
        if (i & 1) {
            if (d2[(i >> 1) + 1] == (i >> 1) + 1) ans += (d[i] = d[i >> 1] + 1);
            else d[i] = 0;
        } else {
            if (d1[i >> 1] == (i >> 1) + 1) ans += (d[i] = d[(i >> 1) - 1] + 1);
            else d[i] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}