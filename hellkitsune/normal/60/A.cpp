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

int n, m;
int from, to, x;
string s;

int main() {
    cin >> n >> m;
    from = 1, to = n;
    REP(i, m) {
        cin >> s >> s >> s;
        bool ri = s[0] == 'r';
        cin >> s >> x;
        if (ri) {
            from = max(from, x + 1);
        } else {
            to = min(to, x - 1);
        }
    }
    if (from > to) {
        cout << -1 << endl;
    } else {
        cout << to - from + 1 << endl;
    }
    return 0;
}