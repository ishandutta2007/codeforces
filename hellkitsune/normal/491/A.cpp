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

int a, b, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    for (int i = b + 1; i <= a + b + 1; ++i)
        cout << i << ' ';
    for (int i = b; i >= 1; --i)
        cout << i << ' ';
    cout << '\n';
    return 0;
}