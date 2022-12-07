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

int n;
string a[1000];
int s[1000];
map<string, int> z, z2;
int mx = -1e9;
int cnt = 0;
string ans;

int main() {
    cin >> n;
    REP(i, n) cin >> a[i] >> s[i];
    REP(i, n) z[a[i]] += s[i];
    foreach(e, z) if (e->second > mx) {
        mx = e->second;
        cnt = 1;
        ans = e->first;
    } else if (e->second == mx)
        ++cnt;
    if (cnt == 1) {
        cout << ans << endl;
        return 0;
    }
    REP(i, n) if ((z2[a[i]] += s[i]) >= mx && z[a[i]] == mx) {
        cout << a[i] << endl;
        return 0;
    }
    return 0;
}