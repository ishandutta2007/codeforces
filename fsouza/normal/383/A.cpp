#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
        lint ret = 0;
        int n;
        cin >> n;

        int nr = 0;
        for (int i = 0; i < n; i++) {
                int dir;
                cin >> dir;
                if (dir == 0) ret += nr;
                else nr++;
        }

        cout << ret << endl;

        return 0;
}