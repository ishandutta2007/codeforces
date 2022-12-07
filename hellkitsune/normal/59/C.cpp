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
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
string s;
bool was[26] = {};
int cnt = 0;

const string IMP = "IMPOSSIBLE";

int main() {
    cin >> k >> s;
    n = (int)s.length();
    for (char c : s) if (c != '?') was[c - 'a'] = true;
    REP(i, k) cnt += !was[i];
    REP(i, (n + 1) / 2) if (s[i] == '?' && s[n - 1 - i] == '?') {
        --cnt;
    }
    if (cnt > 0) {
        cout << IMP << endl;
        return 0;
    }
    REP(i, (n + 1) / 2) if (s[i] != '?' && s[n - 1 - i] != '?' && s[i] != s[n - 1 - i]) {
        cout << IMP << endl;
        return 0;
    }
    REP(i, n) if (s[i] == '?') {
        if (s[n - 1 - i] == '?') {
            if (cnt < 0) {
                s[i] = 'a';
                ++cnt;
            } else {
                REP(j, k) if (!was[j]) {
                    was[j] = true;
                    s[i] = 'a' + j;
                    break;
                }
            }
        } else {
            s[i] = s[n - 1 - i];
        }
    }
    cout << s << endl;
    return 0;
}