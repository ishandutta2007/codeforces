#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <string>
#include <cstring>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9+100;
const ll lINF = 1e18;
const double E = 2.718281828459045;

int hy, ay, dy, hm, am, dm, h, a, d, res=INF;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d;
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            int cur_ay = ay+i;
            int cur_dy = dy+j;
            int l1 = max(0, cur_ay-dm), l2 = max(0, am-cur_dy);
            if (!l1) continue;
            res = min(res, max(0,((hm+l1-1)/l1)* l2 - hy + 1) * h + i*a+j*d);
        }
    }
    cout << res;
    return 0;
}