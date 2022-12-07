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

string n;
vector<string> ans;

int main() {
    cin >> n;
    while (true) {
        string cur;
        REP(i, n.length()) if (n[i] > '0') {
            --n[i];
            cur += '1';
        } else if (!cur.empty()) {
            cur += '0';
        }
        if (cur.empty()) break;
        ans.pb(cur);
    }
    cout << (int)ans.size() << endl;
    for (string x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}