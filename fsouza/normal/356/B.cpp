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

#define INF (INT_MAX/3)
#define MAXS 1000010

typedef long long lint;

using namespace std;

lint gcd(lint a, lint b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

lint temp[26];
lint many[MAXS][26];

bool done[MAXS];

int main(int argc, char ** argv)
{
    lint n, m;
    string x, y;

    cin >> n >> m >> x >> y;

    lint lx = x.size(), ly = y.size();

    if (ly < lx) {
        swap(n, m);
        swap(x, y);
        swap(lx, ly);
    }

    lint minsize = lx*ly/gcd(lx, ly);

    lint minn = minsize / lx;
    lint minm = minsize / ly;

    lint multby = n/minn;
/*
    cout << minsize << endl;
    cout << minn << endl;
    cout << minm << endl;
*/
//  assert(n/minn == m/minm);

    n = minn;
    m = minm;

    lint result = n * lx;

    for (int i = 0; i < ly; i++)
        done[i] = false;

    for (int i = 0; i < ly; i++)
        if (done[i] == false) {
            memset(temp, 0, sizeof(temp));
            temp[y[i]-'a'] ++;
            for (int j = (i + lx)%ly; j != i; j = (j + lx)%ly)
                temp[y[j]-'a'] ++;

            memcpy(many[i], temp, sizeof(temp));
            done[i] = true;
            for (int j = (i + lx)%ly; j != i; j = (j + lx)%ly) {
                memcpy(many[j], temp, sizeof(temp));
                done[j] = true;
            }
        }

    for (int i = 0; i < lx; i++) {
        result -= many[i][x[i]-'a'];
    }

    result *= multby;

    cout << result << endl;

    return 0;
}