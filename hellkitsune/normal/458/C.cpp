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

vector<int> g[100000];
int n;
int q[100000];
priority_queue<int, vector<int>, greater<int> > p;
int cnt = 0, ans = 0, best;

bool cmp(const int &lhs, const int &rhs) {
    return g[lhs].size() < g[rhs].size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        int x, y;
        cin >> x >> y;
        if (x != 0) {
            g[x - 1].pb(y);
            ans += y;
        }
    }
    cnt = n;
    int n = 0;
    REP(i, 100000) if (!g[i].empty()) {
        q[n++] = i;
        sort(g[i].begin(), g[i].end());
    }
    sort(q, q + n, cmp);
    int l = 0;
    best = ans;
    for (int i = 1; l < n; ++i) {
        for (int j = l; j < n; ++j) {
            --cnt;
            ans -= g[q[j]].back();
            p.push(g[q[j]].back());
            g[q[j]].pop_back();
            if (g[q[j]].empty()) ++l;
        }
        while (cnt <= i) {
            ++cnt;
            ans += p.top();
            p.pop();
        }
        best = min(best, ans);
    }
    cout << best << endl;
    return 0;
}