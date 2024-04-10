#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

ll a[999][999];

int main()
{
    for (int i = 1; i <= 99; ++i)
        a[1][i] = a[i][1] = 1ll;
    for (int i = 2; i <= 99; ++i) {
    for (int j = 2; j <= 99; ++j)
    a[i][j] = a[i-1][j] + a[i][j-1];
    }
    int x;
    cin >> x ;
    cout << a[x][x];

    return 0;
}