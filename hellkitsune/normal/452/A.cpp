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

const string t[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
string s;
int n;

int main() {
    cin >> n >> s;
    REP(i, 8) {
        if ((int)t[i].length() != n) continue;
        bool flag = true;
        REP(j, n) if (s[j] != '.' && t[i][j] != s[j]) {
            flag = false;
            break;
        }
        if (flag) {
            cout << t[i] << endl;
            break;
        }
    }
    return 0;
}