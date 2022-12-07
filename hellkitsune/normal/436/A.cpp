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

int n, x;
int t[2000], h[2000], m[2000];
bool used[2000];

int solve(int curt) {
    REP(i, n)
        used[i] = false;
    int res = 0;
    int curx = x;
    while (true) {
        int best = -1;
        for (int i = 0; i < n; ++i)
            if (t[i] == curt && !used[i] && h[i] <= curx && (best == -1 || m[best] < m[i]))
                best = i;
        if (best == -1)
            break;
        ++res;
        curx += m[best];
        used[best] = true;
        curt ^= 1;
    }
    return res;
}

int main() {
    cin >> n >> x;
    REP(i, n)
        cin >> t[i] >> h[i] >> m[i];
    cout << max(solve(0), solve(1)) << endl;
    return 0;
}