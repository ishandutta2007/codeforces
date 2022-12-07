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
LL k;
LL d[55];

void initD() {
    d[0] = d[1] = 1;
    for (int i = 2; i < 55; ++i) {
        d[i] = d[i - 1] + d[i - 2];
    }
}

int main() {
    initD();
    cin >> n >> k;
    for (int i = 0; i < n; ) {
        if (i == n - 1 || d[n - i - 1] >= k) {
            cout << i + 1 << ' ';
            ++i;
        } else {
            cout << i + 2 << ' ' << i + 1 << ' ';
            k -= d[n - i - 1];
            i += 2;
        }
    }
    cout << endl;
    return 0;
}