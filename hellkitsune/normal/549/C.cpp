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

int n, k;
int e = 0, o = 0;
string sta = "Stannis";
string da = "Daenerys";

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        if (x & 1) ++o;
        else ++e;
    }
    if (k == 0) {
        cout << da << endl;
        return 0;
    }
    k = n - k;
    if (k == 0) {
        if (o & 1) cout << sta << endl;
        else cout << da << endl;
        return 0;
    }
    if (!(k & 1)) {
        if (k / 2 >= e && ((n - k) & 1)) cout << sta << endl;
        else cout << da << endl;
        return 0;
    }
    if (k / 2 >= o || (k / 2 >= e && !((n - k) & 1))) cout << da << endl;
    else cout << sta << endl;
    return 0;
}