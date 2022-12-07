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
bool used[1005] = {};

int main() {
    cin >> s;
    for (char &c : s) if (c == ',')
        c = ' ';
    istringstream iss(s);
    int x;
    while (iss >> x) {
        used[x] = true;
    }
    bool flag = false;
    for (int beg = 0; beg < 1005; ) if (used[beg]) {
        int end = beg + 1;
        while (used[end]) ++end;
        if (flag) cout << ',';
        if (end == beg + 1) cout << beg;
        else cout << beg << '-' << end - 1;
        flag = true;
        beg = end;
    } else {
        ++beg;
    }
    cout << endl;
    return 0;
}