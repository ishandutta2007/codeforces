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

int n, x;
int c[100];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> x;
    REP(i, n) cin >> c[i];
    REP(i, n) c[i] *= n - i;
    sort(c, c + n);
    int cnt = 0;
    REP(i, n) if (c[i] <= x) {
        x -= c[i];
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}