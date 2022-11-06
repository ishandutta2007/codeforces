#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

#define MAXN 100000

typedef long long lint;

using namespace std;

int now;
vector <int> adj[MAXN];
char result[MAXN];
bool blocked[MAXN];
int sts[MAXN];
int mark[MAXN];

int totsize, best_midv, value;

void calc_midv(int v)
{
    mark[v] = now;

    int myvalue = totsize - sts[v];

    for (int i = 0; i < adj[v].size(); i++) {
        int v2 = adj[v][i];
        if (!blocked[v2] && mark[v2] < now) {
            calc_midv(v2);
            myvalue = max(myvalue, sts[v2]);
        }
    }

    if (myvalue < value) {
        value = myvalue;
        best_midv = v;
    }
}

void dfs(int v)
{
    mark[v] = now;
    sts[v] = 1;

    for (int i = 0; i < adj[v].size(); i++) {
        int v2 = adj[v][i];
        if (!blocked[v2] && mark[v2] < now) {
            dfs(v2);
            sts[v] += sts[v2];
        }
    }
}

void solve(int _v, char letter)
{
    now ++;
    dfs(_v);

    now ++;
    best_midv = _v;
    value = 1000000000;
    totsize = sts[_v];
    calc_midv(_v);

    int midv = best_midv;

    result[midv] = letter;
    blocked[midv] = true;
    for (int i = 0; i < adj[midv].size(); i++) {
        int v2 = adj[midv][i];
        if (!blocked[v2]) {
            solve(v2, letter+1);
        }
    }
}

int main(int argc, char ** argv)
{
    int n;

    scanf("%d", &n);

    now = 0;

    for (int i = 0; i < n; i++) {
        adj[i].clear();
        mark[i] = 0;
        blocked[i] = false;
    }

    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve(0, 'A');

    for (int i = 0; i+1 < n; i++)
        printf("%c ", result[i]);
    printf("%c\n", result[n-1]);

    return 0;
}