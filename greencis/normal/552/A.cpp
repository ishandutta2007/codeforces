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

int n,xa,ya,xb,yb;
ll ans;

int main()
{
    cin >> n;
    while (n--) {
        cin >> xa >> ya >> xb >> yb;
        ans += ll(xb - xa + 1) * ll(yb - ya + 1);
    }
    cout << ans;

    return 0;
}