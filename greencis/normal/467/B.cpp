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

int n,m,k,a[99999];

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i <= m; ++i) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < m; ++i) {
        int qa = a[i];
        int qb = a[m];
        int qac = 0;
        for (int j = 0; j < n; ++j) {
            qac += (qa ^ qb) & 1;
            qa >>= 1;
            qb >>= 1;
        }
        if (qac <= k) ++res;
    }
    cout << res;

    return 0;
}