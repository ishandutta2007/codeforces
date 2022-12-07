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

int ans, n, k;

int main() {
    cin >> n >> k;
    ans = 0;
    REP(i, n) {
        int x;
        cin >> x;
        if (x + k <= 5)
            ++ans;
    }
    cout << ans / 3 << endl;
    return 0;
}