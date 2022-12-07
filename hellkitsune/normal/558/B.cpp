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

const int MX = 1000001;
int l[MX], r[MX], cnt[MX] = {};
int n;

int main() {
    REP(i, MX) l[i] = 1234567, r[i] = -1;
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        l[x] = min(l[x], i);
        r[x] = max(r[x], i);
        ++cnt[x];
    }
    int best = 0;
    for (int i = 1; i < MX; ++i) if (cnt[i] > cnt[best] || (
        cnt[i] == cnt[best] && r[i] - l[i] < r[best] - l[best])) {
        best = i;
    }
    printf("%d %d\n", l[best] + 1, r[best] + 1);
    return 0;
}