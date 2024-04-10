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

ll m,w;

void fail() {
    printf("NO");
    exit(0);
}

int main()
{
    cin >> w >> m;
    for (int i = 0; i <= 100; ++i) {
        if (m % w == 0) { m /= w; continue; }
        if (m % w == 1) { --m; m /= w; continue; }
        if (m % w == w-1) { ++m; m /= w; continue; }
        fail();
    }
    printf("YES");

    return 0;
}