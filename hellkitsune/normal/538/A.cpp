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
string t = "CODEFORCES";
int n;

int main() {
    cin >> s;
    n = (int)s.length();
    if (n < 10) {
        cout << "NO" << endl;
        return 0;
    }
    int le = 0;
    while (le < 10 && s[le] == t[le]) ++le;
    int ri = 0;
    while (ri < 10 && s[n - 1 - ri] == t[9 - ri]) ++ri;
    if (le + ri < 10) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}