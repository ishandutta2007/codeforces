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

int n;
int cnt[3] = {};

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        x %= 3;
        ++cnt[x];
    }
    printf("%d\n", cnt[0] / 2 + min(cnt[1], cnt[2]));
    return 0;
}