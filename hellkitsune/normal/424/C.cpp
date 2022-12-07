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

int xors[1000001];
int n, ans = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int p;
        scanf("%d", &p);
        ans ^= p;
    }
    xors[0] = 0;
    for (int i = 1; i < n; ++i)
        xors[i] = xors[i - 1] ^ i;
    for (int i = 1; i <= n; ++i) {
        if (((n + 1) / i) & 1)
            ans ^= xors[i - 1];
        int k = n % i;
        if (k != i - 1)
            ans ^= xors[k];
    }
    cout << ans << endl;
    return 0;
}