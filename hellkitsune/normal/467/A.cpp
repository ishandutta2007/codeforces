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
int cnt = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        int x, y;
        cin >> x >> y;
        if (y >= x + 2) ++cnt;
    }
    cout << cnt << endl;
    return 0;
}