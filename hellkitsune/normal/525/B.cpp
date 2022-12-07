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
int n, len;
int rev[100000] = {};
int cur = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> n;
    len = (int)s.length();
    REP(i, n) {
        int x;
        cin >> x, --x;
        rev[x] ^= 1;
    }
    for (int i = 0; 2 * (i + 1) <= len; ++i) {
        cur ^= rev[i];
        if (cur) swap(s[i], s[len - 1 - i]);
    }
    cout << s << endl;
    return 0;
}