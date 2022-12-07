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

int n;
int a[100], sum = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) sum += a[i];
    if (sum % 2 == 0) {
        int mn = sum;
        REP(i, n) if (a[i] % 2 == 1) {
            mn = min(mn, a[i]);
        }
        sum -= mn;
    }
    cout << sum << endl;
    return 0;
}