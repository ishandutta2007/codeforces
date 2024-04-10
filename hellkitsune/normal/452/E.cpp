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

char s[300005];
int n, len;
int ord[300005], c[300005], nord[300005], nc[300005];
int cnt[300005];
stack<PII> st;
LL sum[300005] = {};
const string Z(1, char('z' + 1));
const string ZZ(1, char('z' + 2));
const int MOD = 1e9 + 7;
int C[300005];

char sa[300005], sb[300005], sc[300005];

void solve(bool sub) {
    n = strlen(s) + 1;
    REP(i, 28) cnt[i] = 0;
    cnt[0] = 1;
    REP(i, n - 1) ++cnt[s[i] - 'a'];
    REP(i, 27) cnt[i + 1] += cnt[i];
    REP(i, n - 1) ord[--cnt[s[i] - 'a']] = i;
    ord[0] = n - 1;
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
    REP(i, n) c[ord[i]] = i;
    for (int i = 0, j, k = 0; i < n; cnt[c[i++]] = k) {
        if (c[i] > 0) for (k ? k-- : 0, j = ord[c[i] - 1]; s[i + k] == s[j + k]; k++);
        else k = 0;
    }
    st.push(mp(0, 0));
    for (int i = 2; i < n; ++i) {
        if (cnt[i] < st.top().first) {
            while (cnt[i] < st.top().first) {
                int ccnt = st.top().second;
                if (ccnt >= 2) {
                    int to = st.top().first;
                    st.pop();
                    int from = max(st.top().first, cnt[i]) + 1;
                    int val = C[ccnt + 1];
                    if (sub) val = -val;
                    sum[from] += val;
                    sum[to + 1] -= val;
                } else {
                    st.pop();
                }
                if (cnt[i] > st.top().first) {
                    st.push(mp(cnt[i], ccnt + 1));
                } else if (cnt[i] == st.top().first) {
                    st.top().second += ccnt + 1;
                } else {
                    st.top().second += ccnt;
                }
            }
        } else {
            if (cnt[i] > st.top().first) {
                st.push(mp(cnt[i], 1));
            } else {
                ++st.top().second;
            }
        }
    }
    while (st.top().first != 0) {
        int ccnt = st.top().second;
        if (ccnt >= 2) {
            int to = st.top().first;
            st.pop();
            int from = st.top().first + 1;
            int val = C[ccnt + 1];
            if (sub) val = -val;
            sum[from] += val;
            sum[to + 1] -= val;
        } else {
            st.pop();
        }
        st.top().second += ccnt;
    }
}

int main() {
    for (int i = 3; i < 300005; ++i) C[i] = i * LL(i - 1) * (i - 2) / 6 % MOD;
    scanf("%s%s%s", sa, sb, sc);
    strcpy(s, string(string(sa) + Z + string(sb) + ZZ + string(sc)).c_str());
    solve(false);
    strcpy(s, string(string(sa) + Z + string(sb)).c_str());
    solve(true);
    strcpy(s, string(string(sa) + Z + string(sc)).c_str());
    solve(true);
    strcpy(s, string(string(sb) + Z + string(sc)).c_str());
    solve(true);
    strcpy(s, sa);
    solve(false);
    strcpy(s, sb);
    solve(false);
    strcpy(s, sc);
    solve(false);
    int mn = min(min(strlen(sa), strlen(sb)), strlen(sc));
    LL tot = 0;
    for (int i = 1; i <= mn; ++i) {
        tot += sum[i];
        tot %= MOD;
        if (tot < 0) tot += MOD;
        printf("%d ", (int)tot);
    }
    printf("\n"); 
    return 0;
}