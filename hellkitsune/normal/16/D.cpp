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

int n;
string s;
int tt, t, cnt;
int ans = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    s = "testtest";
    tt = -1;
    REP(i, n) {
        while (s[0] != '[') cin >> s;
        t = ((s[1] - '0') * 10 + s[2] - '0') * 60 + (s[4] - '0') * 10 + (s[5] - '0');
        cin >> s;
        if (s[0] == 'a') {
            if (t >= 12 * 60) t -= 12 * 60;
        } else {
            if (t < 12 * 60) t += 12 * 60;
        }
        if (t > tt) tt = t, cnt = 1;
        else if (t < tt || cnt == 10) {
            tt = t;
            cnt = 1;
            ++ans;
        } else
            ++cnt;
    }
    cout << ans << endl;
    return 0;
}