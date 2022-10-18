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
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

ll n,m;
int u[99],a[99];
int maxdegr;

int main()
{
    cin >> n >> m;
    --m;
    maxdegr = n-2;
    int l = 0, r = n-1;
    for (int i = 0; i < n-1; ++i) {
        if (m & ll(1ll << ll(n-2-i))) a[r] = i+1, --r;
        else a[l] = i+1, ++l;
    }
    a[l] = n;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";

    return 0;
}