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

string s, t;
int cnt[10] = {};

int main() {
    cin >> s >> t;
    REP(i, s.length())
        ++cnt[s[i] - '0'];
    s = "";
    for (int i = 1; i < 10; ++i) if (cnt[i]) {
        --cnt[i];
        s += '0' + i;
        break;
    }
    REP(i, 10) while (cnt[i]) {
        --cnt[i];
        s += '0' + i;
    }
    if (s == t) cout << "OK" << endl;
    else cout << "WRONG_ANSWER" << endl;
    return 0;
}