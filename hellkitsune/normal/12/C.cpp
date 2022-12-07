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

int n, m;
map<string, int> ma;
int p[100];
int cnt[100] = {};
string s;

int main() {
    cin >> n >> m;
    REP(i, n) cin >> p[i];
    REP(i, m) {
        cin >> s;
        ++ma[s];
    }
    int cur = 0;
    foreach(e, ma)
        cnt[cur++] = e->second;
    sort(cnt, cnt + n, greater<int>());
    int ansmin = 0, ansmax = 0;
    sort(p, p + n);
    REP(i, n) ansmin += p[i] * cnt[i];
    reverse(p, p + n);
    REP(i, n) ansmax += p[i] * cnt[i];
    cout << ansmin << ' ' << ansmax << endl;
    return 0;
}