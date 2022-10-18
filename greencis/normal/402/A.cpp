#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int k,a,b,v;

int main()
{
    cin >> k >> a >> b >> v;
    int res = 0;
    while (a > 0) {
        if (b < k-1) {
            a -= (b+1)*v;
            b = 0;
        } else {
            a -= k*v;
            b -= k-1;
        }
        ++res;
    }
    cout << res;

    return 0;
}