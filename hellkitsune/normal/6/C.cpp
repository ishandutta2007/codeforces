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
int a[100000];
int l = 0, r = n - 1;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    if (n == 1) {
        cout << "1 0" << endl;
        return 0;
    }
    l = 0; r = n - 1;
    while (l != r - 1) {
        if (a[l] > a[r]) {
            a[l] -= a[r];
            --r;
        } else {
            a[r] -= a[l];
            ++l;
        }
    }
    cout << l + 1 << ' ' << n - l - 1 << endl;
    return 0;
}