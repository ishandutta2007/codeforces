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
int n, m;
const int MOD = 1e9 + 7;
int p[200003];
int pre[100000];
string z;

void kmp(string &s) {
    int n = (int)s.length();
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            ++j;
        p[i] = j;
    }
}

int st[1 << 18] = {}, sp[1 << 18] = {};
const int off = 1 << 17;

inline void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    n = (int)s.length();
    m = (int)t.length();
    if (m > n) {
        cout << "0\n";
        return 0;
    }
    z = t + "#" + s;
    kmp(z);
    REP(i, n) pre[i] = MOD;
    REP(i, n) if (p[m + 1 + i] == m)
        pre[i - m + 1] = i;
    for (int i = n - 2; i >= 0; --i)
        pre[i] = min(pre[i], pre[i + 1]);
    int mul = 1, incr = 0, ans = 0;
    REP(i, n) {
        if (i) add(incr, st[i - 1]);
        add(mul, incr);
        add(ans, incr);
        if (pre[i] < MOD)
            add(st[pre[i]], mul);
    }
    add(incr, st[n - 1]);
    add(ans, incr);
    cout << ans << endl;
    return 0;
}