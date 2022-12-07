#include <cstdio>
#include <cmath>
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

int n, k;
int a[105];

int main() {
    cin >> n >> k;
    REP(i, n) {
        cin >> a[i];
        a[i] = -a[i];
    }
    sort(a, a + n);
    cout << -a[k - 1] << endl;
    return 0;
}