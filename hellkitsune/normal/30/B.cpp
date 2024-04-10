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
int d, m, y, dd, mm, yy;

void stuff(string &s, int &d, int &m, int &y) {
    d = (s[0] - '0') * 10 + s[1] - '0';
    m = (s[3] - '0') * 10 + s[4] - '0';
    y = (s[6] - '0') * 10 + s[7] - '0';
}

const int cnt[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void q(int d, int m, int y) {
    if (m > 12) return;
    int days = cnt[m];
    if (y % 4 == 0 && m == 2) days = 29;
    if (d > days) return;
    if (yy - y < 18) return;
    if (yy - y == 18) {
        if (m > mm || (m == mm && d > dd)) return;
    }
    cout << "YES\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    stuff(s, dd, mm, yy);
    stuff(t, d, m, y);
    q(d, m, y);
    q(d, y, m);
    q(m, d, y);
    q(m, y, d);
    q(y, d, m);
    q(y, m, d);
    cout << "NO\n";
    return 0;
}