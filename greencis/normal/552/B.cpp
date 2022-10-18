#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n;
ll ans;

int main()
{
    cin >> n;
    if (n <= 9) { cout << n; return 0; }
    int qqq = n;
    int len = 0;
    while (qqq) ++len, qqq /= 10;
    int deg10 = 10;
    ans = 9;
    for (int i = 2; i < len; ++i) {
        deg10 *= 10;
        ans += (ll)i * ll(deg10 - deg10 / 10);
    }
    ans += ll(len) * ll(n - deg10 + 1);
    cout << ans;

    return 0;
}