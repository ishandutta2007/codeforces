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

struct P {
    string s;
    int id;
};

bool cmp(const P &lhs, const P &rhs) {
    return lhs.s < rhs.s;
}

int n;
P p[200000];
int a[100000];
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        cin >> s1 >> s2;
        p[i << 1].s = s1;
        p[(i << 1) | 1].s = s2;
        p[i << 1].id = p[(i << 1) | 1].id = i + 1;
    }
    sort(p, p + (n << 1), cmp);
    REP(i, n) cin >> a[i];
    int pos = 0;
    int mx = n * 2;
    REP(i, n) {
        while (pos < mx && p[pos].id != a[i]) ++pos;
        if (pos == mx) {
            cout << "NO\n";
            return 0;
        }
        ++pos;
    }
    cout << "YES\n";
    return 0;
}