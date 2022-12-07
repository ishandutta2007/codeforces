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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int x, y;

int main() {
    cin >> x >> y;
    x = max(x, y);
    x = 7 - x;
    if (x == 0) cout << "0/1" << endl;
    else if (x == 1) cout << "1/6" << endl;
    else if (x == 2) cout << "1/3" << endl;
    else if (x == 3) cout << "1/2" << endl;
    else if (x == 4) cout << "2/3" << endl;
    else if (x == 5) cout << "5/6" << endl;
    else cout << "1/1" << endl;
    return 0;
}