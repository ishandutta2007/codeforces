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

string s, t;
int a[2][26] = {}, b[2][26] = {};

void stuff(string &s, int (&a)[2][26]) {
    for (char c : s) if (c >= 'a' && c <= 'z')
        ++a[0][c - 'a'];
    else
        ++a[1][c - 'A'];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    stuff(s, a);
    stuff(t, b);
    int ans1 = 0, ans2 = 0;
    REP(i, 26) {
        REP(j, 2) {
            int mn = min(a[j][i], b[j][i]);
            a[j][i] -= mn;
            b[j][i] -= mn;
            ans1 += mn;
        }
        REP(j, 2) {
            int mn = min(a[j][i], b[j ^ 1][i]);
            ans2 += mn;
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}