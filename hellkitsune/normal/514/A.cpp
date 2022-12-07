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

int main() {
    cin >> s;
    bool flag = false;
    for (char &c : s) {
        if ((flag && c == '9') || (c >= '5' && c <= '8')) {
            c = '9' - c + '0';
        }
        flag = true;
    }
    cout << s << endl;
    return 0;
}