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

int n, m, k, p;
int a[1000][1000];
int r[1000], c[1000];
priority_queue<PII> q, q2;
LL ans = 0, cur = 0;
PII tmp[1000];

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &p);
    REP(i, n) REP(j, m) scanf("%d", a[i] + j);
    REP(i, n) {
        r[i] = 0;
        REP(j, m) r[i] += a[i][j];
    }
    REP(i, m) {
        c[i] = 0;
        REP(j, n) c[i] += a[j][i];
    }
    REP(i, n) q.push(mp(r[i], 0));
    REP(i, k) {
        PII e = q.top();
        q.pop();
        cur += e.first;
        e.first -= p * m;
        ++e.second;
        q.push(e);
    }
    REP(i, n) {
        tmp[i] = q.top();
        tmp[i].first += p * m;
        tmp[i].first = -tmp[i].first;
        q.pop();
    }
    REP(i, n) q.push(tmp[i]);
    REP(i, m) q2.push(mp(c[i], 0));
    ans = cur;
    REP(i, k) {
        PII e = q.top();
        while (e.second == 0) {
            q.pop();
            e = q.top();
        }
        q.pop();
        cur += e.first;
        e.first -= p * m;
        --e.second;
        if (e.second != 0) q.push(e);
        e = q2.top();
        q2.pop();
        cur += e.first;
        e.first -= p * n;
        ++e.second;
        q2.push(e);
        ans = max(ans, cur - p * LL(i + 1) * (k - i - 1));
    }
    cout << ans << endl;
    return 0;
}