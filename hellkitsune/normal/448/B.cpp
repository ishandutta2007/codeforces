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
int cnt[26];

int main() {
    cin >> s >> t;
    if (s.length() == t.length()) {
        REP(i, 26) cnt[i] = 0;
        REP(i, s.length()) ++cnt[s[i] - 'a'];
        REP(i, t.length()) --cnt[t[i] - 'a'];
        bool flag = true;
        REP(i, 26) if (cnt[i] != 0) {
            flag = false;
            break;
        }
        if (flag) cout << "array" << endl;
        else cout << "need tree" << endl;
        return 0;
    }
    if (s.length() < t.length()) {
        cout << "need tree" << endl;
        return 0;
    }
    int cur = 0;
    REP(i, s.length()) {
        if (cur < (int)t.length() && t[cur] == s[i]) ++cur;
    }
    if (cur == (int)t.length()) {
        cout << "automaton" << endl;
        return 0;
    }
    REP(i, 26) cnt[i] = 0;
    REP(i, s.length()) ++cnt[s[i] - 'a'];
    REP(i, t.length()) --cnt[t[i] - 'a'];
    REP(i, 26) if (cnt[i] < 0) {
        cout << "need tree" << endl;
        return 0;
    }
    cout << "both" << endl;
    return 0;
}