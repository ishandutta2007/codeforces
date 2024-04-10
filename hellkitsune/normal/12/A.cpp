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

string s[3];
bool ans = true;

int main() {
    REP(i, 3) cin >> s[i];
    ans = ans && (s[0][0] == s[2][2]);
    ans = ans && (s[0][1] == s[2][1]);
    ans = ans && (s[0][2] == s[2][0]);
    ans = ans && (s[1][0] == s[1][2]);
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}