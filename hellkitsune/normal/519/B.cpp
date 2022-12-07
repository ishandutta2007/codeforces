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

multiset<int> a, b;
int n, x;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &x);
        a.insert(x);
    }
    REP(i, n - 1) {
        scanf("%d", &x);
        auto it = a.find(x);
        a.erase(it);
        b.insert(x);
    }
    REP(i, n - 2) {
        scanf("%d", &x);
        auto it = b.find(x);
        b.erase(it);
    }
    assert((int)a.size() == 1);
    assert((int)b.size() == 1);
    printf("%d\n", *a.begin());
    printf("%d\n", *b.begin());
    return 0;
}