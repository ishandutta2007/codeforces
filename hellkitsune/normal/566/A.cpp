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

int n;
char s[800005];
string a[100000], b[100000];
int nx[26][800005] = {};
vector<int> ind[800005], inda[800005];
int nodeCount = 1;
bool used[100000] = {}, useda[100000];
int ans = 0;
int mt[100000];

int dfs(int v) {
    int cnt = 0;
    REP(i, 26) if (nx[i][v]) {
        cnt += dfs(nx[i][v]);
    }
    int tot = min((int)ind[v].size(), (int)inda[v].size()) - cnt;
    int ai = 0, bi = 0;
    REP(i, tot) {
        while (useda[inda[v][ai]]) ++ai;
        while (used[ind[v][bi]]) ++bi;
        useda[inda[v][ai]] = true;
        used[ind[v][bi]] = true;
        mt[inda[v][ai]] = ind[v][bi];
    }
    ans += tot + cnt;
    return cnt + tot;
}

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", s);
        a[i] = string(s);
    }
    REP(i, n) {
        scanf("%s", s);
        b[i] = string(s);
    }
    REP(i, n) {
        int pos = 0;
        ind[0].pb(i);
        for (char ch : b[i]) {
            int c = ch - 'a';
            if (!nx[c][pos]) {
                nx[c][pos] = nodeCount++;
            }
            pos = nx[c][pos];
            ind[pos].pb(i);
        }
    }
    REP(i, n) {
        int pos = 0;
        inda[0].pb(i);
        for (char ch : a[i]) {
            int c = ch - 'a';
            if (!nx[c][pos]) {
                break;
            }
            pos = nx[c][pos];
            inda[pos].pb(i);
        }
    }
    dfs(0);
    printf("%d\n", ans - n);
    REP(i, n) printf("%d %d\n", i + 1, mt[i] + 1);
    return 0;
}