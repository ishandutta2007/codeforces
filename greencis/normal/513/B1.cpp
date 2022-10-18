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

int n,m,a[99];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        a[i] = i+1;
    }

    int mxf = 0;

    do {
        int f = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int mn = 2e9;
                for (int z = i; z <= j; ++z) {
                    mn = min(mn, a[z]);
                }
                f += mn;
            }
        }
        mxf = max(mxf, f);
    } while (next_permutation(a,a+n));

    do {
        int f = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int mn = 2e9;
                for (int z = i; z <= j; ++z) {
                    mn = min(mn, a[z]);
                }
                f += mn;
            }
        }
        if (f == mxf) {
            m--;
            if (!m) {
                for (int i = 0; i < n; ++i)
                    cout << a[i] << " ";
                return 0;
            }
        }
    } while (next_permutation(a,a+n));

    return 0;
}