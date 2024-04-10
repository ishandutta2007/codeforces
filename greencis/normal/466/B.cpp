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

long long n,a,b,s;
long long rs = 9e18,ra=-1,rb=-1,ca,cb;

int main()
{
    cin >> n >> a >> b;
    bool f = false;
    if (a > b) {
        swap(a,b);
        f = true;
    }
    n *= 6;

    for (long long i = 1; i <= n; ++i) {
        long long x = i, y = (n + i - 1) / i;
        if (y < x) break;
        x = max(x,a);
        y = max(y,b);
        if (x*y < rs) {
            rs = x*y;
            ra = x;
            rb = y;
        }
    }

    if (f) swap(ra,rb);
    cout << rs << endl << ra << " " << rb;

    return 0;
}