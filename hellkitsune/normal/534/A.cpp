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

int n;

int main() {
    cin >> n;
    if (n < 3) cout << "1\n1\n";
    else if (n == 3) cout << "2\n1 3\n";
    else {
        cout << n << endl;
        for (int i = 2; i <= n; i += 2) cout << i << ' ';
        for (int i = 1; i <= n; i += 2) cout << i << ' ';
        cout << endl;
    }
    return 0;
}