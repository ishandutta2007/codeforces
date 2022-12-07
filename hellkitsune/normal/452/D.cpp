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

int k;
priority_queue<int, vector<int>, greater<int> > z[3];
int n[3], t[3], sumt[3];
int ans = 0;

int main() {
    cin >> k;
    REP(i, 3) cin >> n[i];
    REP(i, 3) cin >> t[i];
    REP(i, 3) {
        REP(j, n[i]) z[i].push(0);
    }
    sumt[0] = 0;
    sumt[1] = t[0];
    sumt[2] = t[0] + t[1];
    REP(i, k) {
        REP(j, 3) {
            n[j] = z[j].top();
            z[j].pop();
        }
        int st = 0;
        REP(j, 3) st = max(st, n[j] - sumt[j]);
        REP(j, 3) n[j] = st + sumt[j] + t[j];
        ans = n[2];
        REP(j, 3) z[j].push(n[j]);
    }
    cout << ans << endl;
    return 0;
}