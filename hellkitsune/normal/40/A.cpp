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

int x, y;

int main() {
    cin >> x >> y;
    int z = 0;
    while (z * z < x * x + y * y) ++z;
    if (x == 0 || y == 0 || z * z == x * x + y * y) {
        cout << "black" << endl;
        return 0;
    }
    int ans;
    if ((x > 0 && y > 0) || (x < 0 && y < 0)) ans = 1;
    else ans = 0;
    if (z & 1) ans ^= 1;
    if (ans == 1) cout << "white" << endl;
    else cout << "black" << endl;
    return 0;
}