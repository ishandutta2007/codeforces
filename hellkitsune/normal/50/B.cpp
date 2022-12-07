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

char s[100005];
int n;

int cToI(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - '0' + 26;
}

int cnt[66] = {};

int main() {
    scanf("%s", &s);
    n = strlen(s);
    REP(i, n) ++cnt[cToI(s[i])];
    LL ans = 0;
    REP(i, 66) ans += (LL)cnt[i] * cnt[i];
    cout << ans << endl;
    return 0;
}