#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int px, py, vx, vy;

int main() {
    cin >> px >> py >> vx >> vy;
    while (true) {
        if ((vx - px > vy - py && py) || !px) --py;
        else --px;
        if (px == 0 && py == 0) {
            cout << "Polycarp" << endl;
            return 0;
        }
        if (vx) --vx;
        if (vy) --vy;
        if (vx == 0 && vy == 0) {
            cout << "Vasiliy" << endl;
            return 0;
        }
        if (vx == px && vy == py) {
            cout << "Polycarp" << endl;
            return 0;
        }
    }
    return 0;
}