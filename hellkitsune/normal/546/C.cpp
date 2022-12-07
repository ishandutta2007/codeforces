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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
queue<int> q[2];

int main() {
    cin >> n;
    REP(i, 2) {
        int x;
        cin >> x;
        REP(j, x) {
            int val;
            cin >> val;
            q[i].push(val);
        }
    }
    for (int i = 1; i <= 33000000; ++i) {
        int v0 = q[0].front();
        int v1 = q[1].front();
        q[0].pop(), q[1].pop();
        if (v0 > v1) {
            q[0].push(v1);
            q[0].push(v0);
            if (q[1].empty()) {
                printf("%d %d\n", i, 1);
                return 0;
            }
        } else {
            q[1].push(v0);
            q[1].push(v1);
            if (q[0].empty()) {
                printf("%d %d\n", i, 2);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}