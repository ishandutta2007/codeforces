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

string s;
int cnt = 0, ans = 0;

int main() {
    while (!cin.eof()) {
        s = "";
        getline(cin, s);
        if (s.empty()) break;
        if (s[0] == '+') ++cnt;
        else if (s[0] == '-') --cnt;
        else {
            size_t x = s.find(':');
            if (x != string::npos) {
                ans += ((int)s.length() - (int)x - 1) * cnt;
            }
        }
    }
    cout << ans << endl;
    return 0;
}