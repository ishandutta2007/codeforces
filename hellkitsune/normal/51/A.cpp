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

int n;
string s;
int a[4];
set<int> se;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        cin >> s;
        a[0] = s[0] - '0';
        a[1] = s[1] - '0';
        cin >> s;
        a[3] = s[0] - '0';
        a[2] = s[1] - '0';
        if (i < n - 1) cin >> s;
        int mn = (int)1e9;
        REP(j, 4) {
            int cur = 0;
            REP(k, 4) cur = 11 * cur + a[k];
            mn = min(mn, cur);
            if (j < 3) {
                int tmp = a[0];
                REP(k, 3) a[k] = a[k + 1];
                a[3] = tmp;
            }
        }
        se.insert(mn);
    }
    cout << (int)se.size() << endl;
    return 0;
}