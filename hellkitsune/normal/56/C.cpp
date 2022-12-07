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

string s;
int len, n = 0;
string na[1000];
vector<int> g[1000];

int pos = 0;
void go() {
    int cur = n++;
    while (s[pos] >= 'A' && s[pos] <= 'Z') {
        na[cur] += s[pos];
        ++pos;
    }
    while (s[pos] != '.') {
        ++pos;
        g[cur].pb(n);
        go();
    }
    ++pos;
}

int ans = 0;
string bad;

void dfs(int v) {
    if (na[v] == bad) ++ans;
    for (int to : g[v]) {
        dfs(to);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    len = (int)s.length();
    go();
    REP(i, n) {
        bad = na[i];
        --ans;
        dfs(i);
    }
    cout << ans << endl;
    return 0;
}