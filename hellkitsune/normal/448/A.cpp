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

int a1, a2, a3, b1, b2, b3, a, b, n;

int main() {
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
    a = a1 + a2 + a3;
    b = b1 + b2 + b3;
    n -= a / 5;
    if (a % 5) --n;
    n -= b / 10;
    if (b % 10) --n;
    if (n < 0) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}