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

int a[4];
string s;

int ans;

int main() {
    REP(i, 4) cin >> a[i];
    cin >> s;
    ans = 0;
    REP(i, s.length())
        ans += a[s[i] - '1'];
    cout << ans << endl;
    return 0;
}