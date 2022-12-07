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

bool was[5555] = {};
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        int x;
        cin >> x;
        was[x] = true;
    }
    for (int i = 1; i < 5555; ++i) if (!was[i]) {
        cout << i << endl;
        return 0;
    }
    return 0;
}