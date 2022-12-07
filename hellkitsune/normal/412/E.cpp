#include <cstdio>
#include <cmath>
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

string s;
int n, cfirst[1000000], csecond[1000000], cthird[1000000];
LL ans = 0;

int main() {
    cin >> s;
    n = s.length();
    int cur = 0;
    REP(i, n) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            ++cur;
        } else if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '_')) {
            //
        } else
            cur = 0;
        cfirst[i] = cur;
    }
    cur = -1;
    REP(i, n) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            //
        } else {
            cur = i;
        }
        csecond[i] = cur;
    }
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] >= 'a' && s[i] <= 'z')
            ++cur;
        else
            cur = 0;
        cthird[i] = cur;
    }
    int wasat = -1;
    REP(i, n - 1)
        if (s[i] == '@')
            wasat = i;
        else if (s[i] == '.') {
            if (wasat != -1 && csecond[i - 1] == wasat && wasat && i > wasat + 1)
                ans += (LL)cfirst[wasat - 1] * cthird[i + 1];
            wasat = -1;
        }
    cout << ans << endl;
    return 0;
}