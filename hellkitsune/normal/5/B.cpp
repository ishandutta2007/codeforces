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

string s[1010];
int mx = 0;
bool flag = true;

int main() {
    int n = 0;
    while (true) {
        getline(cin, s[n++]);
        if (cin.eof()) {
            break;
        }
    }
    --n;
    REP(i, n)
        mx = max(mx, (int)s[i].length());
    REP(i, n) {
        int cur = s[i].length();
        if ((mx - cur) / 2 > 0) {
            string spac((mx - cur) / 2, ' ');
            s[i] = spac + s[i] + spac;
        }
        if ((mx - cur) % 2 == 1) {
            if (!flag) s[i] = " " + s[i];
            else s[i] += ' ';
            if (cur != 0)
                flag = !flag;
        }
        s[i] = "*" + s[i] + "*";
    }
    string stars(mx + 2, '*');
    cout << stars << endl;
    REP(i, n) cout << s[i] << endl;
    cout << stars << endl;
    return 0;
}