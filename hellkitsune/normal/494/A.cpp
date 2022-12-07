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
int cnt = 0, lst, pos = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = (int)s.length();
    int bal = 0;
    REP(i, n) if (s[i] == '(') ++bal;
    else if (s[i] == ')' || s[i] == '#') --bal;
    lst = bal;
    if (lst < 0) {
        cout << "-1\n";
        return 0;
    }
    REP(i, n) if (s[i] == '#') pos = i;
    bal = 0;
    REP(i, n) if (s[i] == '(')
        ++bal;
    else if (s[i] == ')' || s[i] == '#') {
        if (s[i] == '#') ++cnt;
        --bal;
        if (i == pos) bal -= lst;
        if (bal < 0) {
            cout << "-1\n";
            return 0;
        }
    }
    REP(i, cnt - 1) cout << 1 << '\n';
    if (cnt) cout << 1 + lst << '\n';
    return 0;
}