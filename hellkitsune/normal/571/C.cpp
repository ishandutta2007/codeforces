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

int n, m;
vector<pair<int, bool> > pos[200005];
vector<int> vars[200005];
bool used[200005] = {};
int ans[200005] = {};
bool done[200005] = {};
int rem[200005];
char sans[200005];

queue<int> q;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) {
        int cnt;
        scanf("%d", &cnt);
        REP(j, cnt) {
            int x;
            scanf("%d", &x);
            bool rev = x < 0;
            if (rev) x = -x;
            --x;
            pos[x].pb(mp(i, rev));
            vars[i].pb(x);
        }
    }
    REP(i, m) {
        used[i] = (int)pos[i].size() < 2;
        if ((int)pos[i].size() == 1) {
            done[pos[i][0].first] = true;
            if (pos[i][0].second) ans[i] = 0;
            else ans[i] = 1;
        } else if (!pos[i].empty() && pos[i][0].second == pos[i][1].second) {
            done[pos[i][0].first] = done[pos[i][1].first] = true;
            used[i] = true;
            if (pos[i][0].second) ans[i] = 0;
            else ans[i] = 1;
        }
    }
    REP(i, n) if (done[i]) q.push(i);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int x : vars[v]) if (!used[x]) {
            for (auto y : pos[x]) if (!done[y.first]) {
                q.push(y.first);
                done[y.first] = true;
                used[x] = true;
                if (y.second) ans[x] = 0;
                else ans[x] = 1;
                break;
            }
        }
    }
    REP(i, n) if (!done[i]) {
        rem[i] = 0;
        for (int x : vars[i]) if (!used[x]) {
            ++rem[i];
        }
        if (rem[i] == 1) q.push(i);
    }
    int ind = 0;
    while (true) {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int x : vars[v]) if (!used[x]) {
                done[v] = true;
                used[x] = true;
                for (auto y : pos[x]) {
                    if (--rem[y.first] == 1 && !done[y.first]) {
                        q.push(y.first);
                    }
                    if (y.first == v) {
                        if (y.second) ans[x] = 0;
                        else ans[x] = 1;
                    }
                }
                break;
            }
        }
        while (ind < n && done[ind]) ++ind;
        if (ind == n) break;
        q.push(ind);
        ++ind;
    }
    REP(i, n) if (!done[i]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    REP(i, m) sans[i] = ans[i] + '0';
    sans[m] = '\0';
    printf("%s\n", sans);
    return 0;
}