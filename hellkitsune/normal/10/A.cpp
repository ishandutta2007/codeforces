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

int n, P1, P2, P3, T1, T2;
int l[100], r[100];
int ans = 0;

int main() {
    cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;
    REP(i, n) {
        cin >> l[i] >> r[i];
        ans += (r[i] - l[i]) * P1;
    }
    REP(i, n - 1) {
        int t = l[i + 1] - r[i];
        ans += min(T1, t) * P1;
        t -= T1;
        ans += max(0, min(T2, t)) * P2;
        t -= T2;
        ans += max(0, t) * P3;
    }
    cout << ans << endl;
    return 0;
}