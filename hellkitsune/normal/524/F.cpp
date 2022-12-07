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

char s[2000005], t[1000005];
int n;
int bal[2000005];
int ord[1000005], c[1000005], nord[1000005], nc[1000005];
int cnt[1000005];
stack<int> st;
bool mt[2000005];

int main() {
    scanf("%s", s);
    n = strlen(s);
    REP(i, 2) cnt[i] = 0;
    REP(i, n) ++cnt[s[i] == '(' ? 0 : 1];
    REP(i, 1) cnt[i + 1] += cnt[i];
    REP(i, n) ord[--cnt[s[i] == '(' ? 0 : 1]] = i;
    c[ord[0]] = 0;
    int cpos = 0;
    for (int i = 1; i < n; ++i) {
        if (s[ord[i - 1]] != s[ord[i]]) ++cpos;
        c[ord[i]] = cpos;
    }
    for (int sz = 1; sz < n; sz <<= 1) {
        REP(i, n) {
            nord[i] = ord[i] - sz;
            if (nord[i] < 0) nord[i] += n;
        }
        REP(i, n) cnt[i] = 0;
        REP(i, n) ++cnt[c[nord[i]]];
        REP(i, n - 1) cnt[i + 1] += cnt[i];
        for (int i = n - 1; i >= 0; --i)
            ord[--cnt[c[nord[i]]]] = nord[i];
        nc[ord[0]] = 0;
        cpos = 0;
        for (int i = 1; i < n; ++i) {
            int mid1 = ord[i - 1] + sz, mid2 = ord[i] + sz;
            if (mid1 >= n) mid1 -= n;
            if (mid2 >= n) mid2 -= n;
            if (c[ord[i - 1]] != c[ord[i]] || c[mid1] != c[mid2]) ++cpos;
            nc[ord[i]] = cpos;
        }
        REP(i, n) c[i] = nc[i];
    }
    REP(i, n) s[n + i] = s[i];
    int N = n << 1;
    int mx = 0, cbal = 0;
    REP(i, N) {
        if (s[i] == '(') st.push(i);
        else if (!st.empty()) {
            ++cbal;
            mt[st.top()] = true;
            st.pop();
        }
        if (i >= n && mt[i - n])
            --cbal;
        bal[i] = cbal;
        mx = max(mx, cbal);
    }
    int best = -1;
    REP(i, n) if (bal[ord[i] - 1 + n] == mx) {
        best = ord[i];
        break;
    }
    int cur = 0, cnt = 0;
    for (int i = best; i < best + n; ++i) {
        int pos = i % n;
        cur += s[pos] == '(' ? 1 : -1;
        if (cur < 0) ++cur, ++cnt;
    }
    while (cnt > 0) printf("("), --cnt;
    for (int i = best; i < best + n; ++i) {
        int pos = i % n;
        printf("%c", s[pos]);
    }
    while (cur > 0) printf(")"), --cur;
    printf("\n");
    return 0;
}