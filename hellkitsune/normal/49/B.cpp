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

int a[10] = {}, b[10] = {};
int n;

void parseInt(int n, int *a) {
    int pos = 0;
    while (n) {
        a[pos++] = n % 10;
        n /= 10;
    }
}

int main() {
    cin >> n;
    parseInt(n, a);
    cin >> n;
    parseInt(n, b);
    int mx = 0;
    REP(i, 10) mx = max(mx, a[i]);
    REP(i, 10) mx = max(mx, b[i]);
    int base = mx + 1;
    REP(i, 9) {
        a[i] += b[i];
        a[i + 1] += a[i] / base;
        a[i] %= base;
    }
    int ans = 0;
    REP(i, 10) if (a[i]) {
        ans = i + 1;
    }
    cout << ans << endl;
    return 0;
}