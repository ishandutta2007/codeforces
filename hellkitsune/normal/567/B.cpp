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
typedef long long LL;
typedef pair<int, int> PII;

int mx = 0, cur = 0;
int n, x;
char qt[5];
set<int> se;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s%d", qt, &x);
        if (qt[0] == '+') {
            se.insert(x);
            if (++cur > mx) mx = cur;
        } else {
            auto it = se.find(x);
            if (it == se.end()) {
                ++mx;
            } else {
                --cur;
            }
        }
    }
    printf("%d\n", mx);
    return 0;
}