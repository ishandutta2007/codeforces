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

int n,m,x,y,a[10005],b[10005];

int main()
{
    cin >> n >> m;
    cin >> x;
    while (x--) { cin >> y; a[y] = 1; }
    cin >> x;
    while (x--) { cin >> y; b[y] = 1; }
    int cura = 0, curb = 0;
    for (int i = 0; i < 1000000; ++i) {
        if (a[cura] == 1 || b[curb] == 1) a[cura] = 1, b[curb] = 1;
        ++cura %= n; ++curb %= m;
    }
    bool good = true;
    for (int i = 0; i < n; ++i)
        good &= a[i];
    for (int i = 0; i < m; ++i)
        good &= b[i];
        if (good) cout << "Yes"; else cout << "No";


    return 0;
}