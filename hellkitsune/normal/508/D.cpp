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

int n;
int g[3844][3844] = {};
int pos[3844] = {}, rem[3844] = {};
int vin[3844] = {}, vout[3844] = {};
char ss[5];
int st, fn, nz;

inline int ctoi(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'z') return c - 'a' + 10;
    return c - 'A' + 36;
}

inline char itoc(int i) {
    if (i < 10) return '0' + i;
    if (i < 36) return 'a' + (i - 10);
    return 'A' + (i - 36);
}

stack<int> s;
vector<int> ans, tmp;
char ret[222222];

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", ss);
        int from = ctoi(ss[0]) * 62 + ctoi(ss[1]);
        int to = ctoi(ss[1]) * 62 + ctoi(ss[2]);
        ++vout[from];
        ++vin[to];
        ++g[from][to];
    }
    int acnt = 0, bcnt = 0;
    REP(i, 3844) {
        if (vin[i] || vout[i]) nz = i;
        if (vin[i] == vout[i]) continue;
        if (vin[i] == vout[i] + 1)
            ++acnt, fn = i;
        else if (vout[i] == vin[i] + 1)
            ++bcnt, st = i;
        else {
            printf("NO\n");
            return 0;
        }
    }
    bool flag = false;
    if (acnt == 0 && bcnt == 0) {
        st = fn = nz;
        flag = true;
    } else if (acnt != 1 || bcnt != 1) {
        printf("NO\n");
        return 0;
    }
    if (!flag) {
        ++g[fn][st];
    }
    s.push(st);
    REP(i, 3844) REP(j, 3844) rem[i] += g[i][j];
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        while (rem[v]) {
            s.push(v);
            --rem[v];
            while (g[v][pos[v]] == 0) ++pos[v];
            --g[v][pos[v]];
            v = pos[v];
        }
        ans.pb(v);
    }
    reverse(ans.begin(), ans.end());
    if (!flag) {
        int sz = (int)ans.size();
        ans.resize(sz - 1);
        --sz;
        REP(i, sz - 1) if (ans[i] == fn && ans[i + 1] == st) {
            for (int j = i + 1; j < sz; ++j)
                tmp.pb(ans[j]);
            REP(j, i + 1)
                tmp.pb(ans[j]);
            ans = tmp;
            tmp.clear();
            break;
        }
    }
    if ((int)ans.size() + 1 != n + 2) {
        printf("NO\n");
        return 0;
    }
    REP(i, ans.size()) {
        ret[i] = itoc(ans[i] / 62);
    }
    ret[(int)ans.size()] = itoc(ans[(int)ans.size() - 1] % 62);
    ret[(int)ans.size() + 1] = '\0';
    printf("YES\n");
    printf("%s\n", ret);
    return 0;
}