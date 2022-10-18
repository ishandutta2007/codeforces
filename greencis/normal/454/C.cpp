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

int n,m;
long long res;
long double res2;

long double binpow(long double nn, int k) {
    if (k == 0) return (long double)1;
    if (k == 1) return nn;
    if (k % 2 == 0) {
        long double r = binpow(nn, k/2);
        return r*r;
    } else {
        long double r = binpow(nn, k/2);
        return r*r*nn;
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        res2 += i * (binpow(i*1./m,n) - binpow((i-1)*1./m,n));
    }
    cout.precision(17);
    cout << fixed << res2;

    return 0;
}