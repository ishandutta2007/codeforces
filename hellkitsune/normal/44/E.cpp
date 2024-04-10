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

int k, a, b;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> k >> a >> b >> s;
    int len = (int)s.length();
    if (k * a > len || k * b < len) {
        cout << "No solution" << endl;
        return 0;
    }
    int rem = len - k * a;
    int pos = 0;
    REP(i, k) {
        int cur = min(b, a + rem);
        rem -= cur - a;
        cout << s.substr(pos, cur) << endl;
        pos += cur;
    }
    return 0;
}