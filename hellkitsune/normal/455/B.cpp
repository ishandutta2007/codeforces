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

int n, k;
string s[100000];
int t[100005][26], cnt = 1;
bool w[100005];
bool l[100005];

void go(int v) {
    bool win = false;
    REP(i, 26) if (t[v][i] != -1) {
        go(t[v][i]);
        if (!w[t[v][i]]) win = true;
    }
    w[v] = win;
}

void go2(int v) {
     bool lose = false, zero = true;
     REP(i, 26) if (t[v][i] != -1) {
        zero = false;
        go2(t[v][i]);
        if (!l[t[v][i]]) lose = true;
     }
     l[v] = lose || zero;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    REP(i, n) cin >> s[i];
    REP(i, 26) t[0][i] = -1;
    REP(i, n) {
        int cur = 0;
        for (char j : s[i]) {
            if (t[cur][j - 'a'] == -1) {
                REP(z, 26) t[cnt][z] = -1;
                t[cur][j - 'a'] = cnt++;
            }
            cur = t[cur][j - 'a'];
        }
    }
    go(0);
    go2(0);
    if (w[0]) {
        if (k % 2 == 0 && !l[0]) cout << "Second" << endl;
        else cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}